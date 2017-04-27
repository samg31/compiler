#include <sstream>
#include <iostream>

#include "check.hpp"
#include "eval.hpp"
#include "translator.hpp"
#include "util.hpp"

translator::translator( context& cxt, std::list<scope>& stack, value_map& vm )
	:m_cxt( cxt ), m_stack( stack ), m_values( vm ), next_type()
{
}

expr* translator::on_cond( expr& ast_1, expr& ast_2, expr& ast_3 )
{
	if( check( ast_1 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in conditional expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( check( ast_2 ) != check( ast_3 ) )
	{
		std::stringstream ss;
		ss << "Expected resultant expressions to be of the same type.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	
	return new cond_expr( ast_1, ast_2, ast_3, m_cxt );
}

expr* translator::on_or( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( check( ast_2 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return new or_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_and( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	if( check( ast_2 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return new and_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_equal( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != check( ast_2 ) )
	{
		std::stringstream ss;
		ss << "Expected same types in equality expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	
	return new equal_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_inequal( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != check( ast_2 ) )
	{
		std::stringstream ss;
		ss << "Expected same types in inequality expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	
	return new inequal_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_less( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new less_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_greater( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new greater_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_lesseq( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new lesseq_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_greatereq( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new greatereq_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_add( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new add_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_sub( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new sub_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_mul( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new mul_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_div( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new div_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_rem( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 1.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}
	if( check( ast_2 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in expression 2.\n";
		throw std::runtime_error( ss.str().c_str() );		
	}

	return new rem_expr( ast_1, ast_2, m_cxt );
}

expr* translator::on_not( expr& ast_1 )
{
	if( check( ast_1 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in not expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return new not_expr( ast_1, m_cxt );
}

expr* translator::on_neg( expr& ast_1 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in neg expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return new neg_expr( ast_1, m_cxt );
}

expr* translator::on_ref( id_token& identifier )
{
	auto declaration = scope_lookup( m_stack, identifier.get_name() );

	// if the declaration was not found in any scope
	if( !declaration )
	{
		std::stringstream ss;
		// ss << "Use of undeclared identifier " << identifier.get_name() << '\n';
		throw std::runtime_error( ss.str().c_str() );
	}

	auto val = static_cast<var_decl*>( declaration );
	auto it = m_values.find( declaration );
	auto ty = val->m_type;
	return new ref_expr( declaration, it->second, ty, m_cxt );
}

expr* translator::on_assign( expr* ast_1, expr* ast_2 )
{
	auto var = static_cast<ref_expr*>( ast_1 );
	auto ref = static_cast<var_decl*>( var->get_reference() );
	auto declaration = scope_lookup( m_stack, ref->m_name );

	// if the declaration was not found in any scope
	if( !declaration )
	{
		std::stringstream ss;
		// ss << "Use of undeclared identifier " << identifier.get_name() << '\n';
		throw std::runtime_error( ss.str().c_str() );
	}

	var->set_value( ast_2 );
	auto it = m_values.find( declaration );
	it->second = ast_2;
	
	return var;
}

stmt* translator::on_decl_stmt( decl* d )
{
	return new decl_stmt( d );
}

stmt* translator::on_expr_stmt( expr* e )
{
	return new expr_stmt( e );
}

decl* translator::on_var_decl( const type* t, symbol* n )
{
	var_decl* var = new var_decl( n, t );

	// add the declaration to the scope
	if( m_stack.front().insert( n, var ) )
		return var;
	
	// insertion will fail if this (name,decl) mapping already exists
	else
	{
		std::stringstream ss;
		ss << "identifier" << *n << "already exists\n";
		throw std::runtime_error( ss.str().c_str() );
	}
}

decl* translator::on_var_compl( decl* d, expr* e )
{
	var_decl* var = static_cast<var_decl*>( d );
	var->m_type = next_type;
	next_type = nullptr;
	var->set_init( e );
	m_values.insert( {d, e} );
	return var;
}

const type* translator::on_bool_type()
{
	next_type = &m_cxt.bool_ty;
}

const type* translator::on_int_type()
{
	next_type = &m_cxt.int_ty;
}

symbol* translator::on_id( token* t )
{
	auto id = dynamic_cast<id_token*>( t );
	return id->get_name();
}
