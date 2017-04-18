#include <cassert>
#include <iostream>

#include "parser.hpp"
#include "check.hpp"
#include "eval.hpp"

parser::parser( lexer& l, context& cxt )
	:m_lexer( l ), m_cxt( cxt ), sema( translator( cxt ) )
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

expr_ptr parser::expression()
{
	return conditional_expression();
}

expr_ptr parser::conditional_expression()
{
	auto ast_1 = logical_or_expression();
	while( true )
	{
		if( match_if( question_tok ) )
		{
			auto ast_2 = expression();

			match( colon_tok );
			
			auto ast_3 = expression();
			ast_1 = std::move( sema.on_cond( *ast_1, *ast_2, *ast_3 ) );
		}
		else break;
	}
	return ast_1;	
}

expr_ptr parser::logical_or_expression()
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

expr_ptr parser::logical_and_expression()
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

expr_ptr parser::equality_expression()
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

expr_ptr parser::ordering_expression()
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

expr_ptr parser::additive_expression()
{
	auto ast_1 = multiplicative_expression();
	expr_ptr r;
	while( true )
	{
		if( match_if( plus_tok ) )
		{
			auto ast_2 = multiplicative_expression();
			r = sema.on_add( *ast_1, *ast_2 );
			std::cout << eval( *r ) << '\n';
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

expr_ptr parser::multiplicative_expression()
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

expr_ptr parser::unary_expression()
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

expr_ptr parser::primary_expression()
{
	switch( lookahead() )
	{
 	case int_tok:
	{
		auto p = &(*consume() );
		auto q = static_cast<int_token*>( p );
		auto r = expr_ptr( new int_expr( q->get_value(), m_cxt ) );
		return r;
		break;
	}
	case true_kw_tok:
	case false_kw_tok:
	{
		auto next = static_cast<bool_token*>( &(*consume()) );
		return expr_ptr( new bool_expr( next->get_value(), m_cxt ) );
		break;
	}
	case lparen_tok:
	{
		consume();
		auto e = expression();
		match( rparen_tok );
		return e;
	}
	}

	return nullptr;
}

	
