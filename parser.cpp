#include <cassert>
#include <iostream>

#include "parser.hpp"
#include "util.hpp"
#include "check.hpp"
#include "eval.hpp"
#include "context.hpp"

parser::parser( lexer& l, context& cxt, std::list<scope>& stack, value_map& vm )
	:m_lexer( l ), m_cxt( cxt ), sema( translator( cxt, stack, vm ) ),
	 m_stack( stack ), m_values( vm )
{
	m_lexer.lex();
	if( auto token = std::move( m_lexer.front() ) )
	{
		tokens.push_front( std::move( token ) );
	}
}

token_kind parser::lookahead()
{
	if( !tokens.empty() )
		return tokens.front()->get_kind();
	else
		return eof_tok;
}

token_ptr parser::consume()
{
	assert( !tokens.empty() );

	auto token = std::move( tokens.front() );
	tokens.pop_front();
	
	if( tokens.empty() )
	{
		if( auto next = m_lexer.front() )
		{
			tokens.push_front( std::move( next ) );
		}
	}
	
	return token;
}

token_ptr parser::match( token_kind tk )
{
	if( lookahead() == tk )
		return consume();
	else		
		throw std::runtime_error( "unexpected token in lookahead\n" );
}

token_ptr parser::match_if( token_kind tk )
{
	if ( lookahead() == tk )
	{
		return consume();
	}
	else
	{
		return nullptr;
	}
}

expr* parser::expression()
{
	return assignment_expression();
}

expr* parser::assignment_expression()
{
	auto ast_1 = conditional_expression();

	while( true )
	{
		if( match_if( assign_tok ) )
		{
			auto ast_2 = logical_or_expression();
			ast_1 = sema.on_assign( ast_1, ast_2 );
		}
		else break;
	}
	return ast_1;
}

expr* parser::conditional_expression()
{
	auto ast_1 = logical_or_expression();
	while( true )
	{
		if( match_if( question_tok ) )
		{
			auto ast_2 = expression();

			match( colon_tok );
			
			auto ast_3 = assignment_expression();
			ast_1 = std::move( sema.on_cond( *ast_1, *ast_2, *ast_3 ) );
		}
		else break;
	}
	return ast_1;	
}

expr* parser::logical_or_expression()
{
	auto ast_1 = logical_and_expression();
	while( true )
	{
		if( match_if( bar_tok ) )
		{
			auto ast_2 = logical_and_expression();
			ast_1 = sema.on_or( *ast_1, *ast_2 );
		}
		else break;
	}
	return ast_1;
}

expr* parser::logical_and_expression()
{
	auto ast_1 = equality_expression();
	while( true )
	{
		if( match_if( ampersand_tok ) )
		{
			auto ast_2 = equality_expression();
			ast_1 = sema.on_and( *ast_1, *ast_2 );
		}
		else break;
	}
	return ast_1;
}

expr* parser::equality_expression()
{
	auto ast_1 = ordering_expression();
	while( true )
	{
		if( match_if( equal_tok ) )
		{
			auto ast_2 = ordering_expression();
			ast_1 = sema.on_equal( *ast_1, *ast_2 );
		}
		else if( match_if( exclmeq_tok ) )
		{
			auto ast_2 = ordering_expression();
			ast_1 = sema.on_inequal( *ast_1, *ast_2 );
		}
		else break;
	}
	return ast_1;
}

expr* parser::ordering_expression()
{
	auto ast_1 = additive_expression();
	while( true )
	{
		if( match_if( less_tok ) )
		{
			auto ast_2 = additive_expression();
			ast_1 = sema.on_less( *ast_1, *ast_2 );
		}
		else if( match_if( greater_tok ) )
		{
			auto ast_2 = additive_expression();
			ast_1 = sema.on_greater( *ast_1, *ast_2 );
		}
		else if( match_if( lesseq_tok ) )
		{
			auto ast_2 = additive_expression();
			ast_1 = sema.on_lesseq( *ast_1, *ast_2 );
		}
		else if( match_if( greatereq_tok ) )
		{
			auto ast_2 = additive_expression();
			ast_1 = sema.on_greatereq( *ast_1, *ast_2 );
		}
		else break;
	}

	return ast_1;

}

expr* parser::additive_expression()
{
	auto ast_1 = multiplicative_expression();
	expr* r;
	while( true )
	{
		if( match_if( plus_tok ) )
		{
			auto ast_2 = multiplicative_expression();
			r = sema.on_add( *ast_1, *ast_2 );
			return r;
		}
		else if( match_if( minus_tok ) )
		{
			auto ast_2 = multiplicative_expression();
			r = sema.on_sub( *ast_1, *ast_2 );
			return r;
		}
		else break;
	}
	return ast_1;
}

expr* parser::multiplicative_expression()
{
	auto ast_1 = unary_expression();
	while( true )
	{
		if( match_if( asterix_tok ) )
		{
		    auto ast_2 = unary_expression();
			ast_1 = sema.on_mul( *ast_1, *ast_2 );
		}
		else if( match_if( slash_tok ) )
		{
		    auto ast_2 = unary_expression();
			ast_1 = sema.on_div( *ast_1, *ast_2 );
		}
		else if( match_if( percent_tok ) )
		{
		    auto ast_2 = unary_expression();
			ast_1 = sema.on_rem( *ast_1, *ast_2 );
		}		
		else break;
	}
	return ast_1;
}

expr* parser::unary_expression()
{
	if( match_if( minus_tok ) )
	{
		auto ast_1 = unary_expression();
		return sema.on_neg( *ast_1 );
	}
	else if( match_if( exclm_tok ) )
	{
		auto ast_1 = unary_expression();
		return sema.on_not( *ast_1 );
	}
	else
		return primary_expression();
}

expr* parser::primary_expression()
{
	switch( lookahead() )
	{
 	case int_tok:
	{
		auto p = &(*consume() );
		auto q = static_cast<int_token*>( p );
		auto r = new int_expr( q->get_value(), m_cxt );
		return r;
		break;
	}
	case true_kw_tok:
	case false_kw_tok:
	{
		auto next = static_cast<bool_token*>( &(*consume()) );
		return new bool_expr( next->get_value(), m_cxt );
		break;
	}
	case lparen_tok:
	{
		consume();
		auto e = expression();
		match( rparen_tok );
		return e;
	}
	case id_tok:
	{
		return id_expression();
		
	}
	}

	return nullptr;
}

expr* parser::id_expression()
{
	auto next = &( *consume() );
	auto next_id = static_cast<id_token*>( next );
	return sema.on_ref( *next_id );
}

// STATEMENT PARSING

decl* parser::program()
{
	std::vector<stmt*> sequence;

	while( !tokens.empty() )
	{
		sequence.push_back( statement() );
	}

	return sema.on_program( sequence );
}

stmt* parser::statement()
{
	switch( lookahead() )
	{
	case lbrace_tok:
		return block_statement();
	case var_kw_tok:
		return declaration_statement();
	case print_kw_tok:
		return print_statement();
	case while_kw_tok:
		return while_statement();
	default:
		return expression_statement();
	}
}

stmt* parser::print_statement()
{
	consume();

	// analyze expressions to print until end of statement
	auto e = expression();
	match( semicolon_tok );

	// print the evaluation of the expression
	std::cout << eval( *e ) << '\n';

	// return null because prints do not generate actual code
	return nullptr;
}

stmt* parser::while_statement()
{
	consume();

	match( lparen_tok );
	auto conditional = expression();
	match( rparen_tok );
	auto block = block_statement();
	
	return new while_stmt( conditional, block );
}

stmt* parser::block_statement()
{
	// enter a new block scope
	m_stack.emplace_front();
	stmt_seq seq;

	// consume the initial lbrace_tok
	consume();
	
	while( lookahead() != rbrace_tok )
	{
		seq.push_back( statement() );
	}

	// consume the final rbrace_tok
	consume();
	
	return new block_stmt( seq );
}

stmt* parser::declaration_statement()
{
	decl* d = declaration();
	return sema.on_decl_stmt( d );
}

stmt* parser::expression_statement()
{
	expr* e = expression();
	match( semicolon_tok );
	return sema.on_expr_stmt( e );
}

decl* parser::declaration()
{
	switch( lookahead() )
	{
	case var_kw_tok:
		return variable_declaration();
	}
	throw std::runtime_error( "unexpected declaration\n" );
}

decl* parser::variable_declaration()
{
	consume();

	// determine type, name, and create a declaration object
	auto t = type_specifier();	
	auto n = identifier();
	auto var = sema.on_var_decl( t, n );

	// find an assignment operator
	match( assign_tok );

	// parse the expression on the right side of the operator
	auto e = expression();

	// initialize the declaration
	sema.on_var_compl( var, e );
	// find a semicolon
	match( semicolon_tok );
	
	return var;
}

symbol* parser::identifier()
{
	auto id = match( id_tok );
	return sema.on_id( id.release() );
}

const type* parser::type_specifier()
{
	switch( lookahead() )
	{
	case bool_kw_tok:
		consume();
		return sema.on_bool_type();
	case int_kw_tok:
		consume();
		return sema.on_int_type();
	}
}
