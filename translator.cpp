#include <sstream>
#include <iostream>

#include "check.hpp"
#include "eval.hpp"
#include "translator.hpp"

translator::translator( context& cxt )
	:m_cxt( cxt )
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
	// add the declaration of n as a variable
	return var;
}

decl* translator::on_var_compl( decl* d, expr* e )
{
	var_decl* var = static_cast<var_decl*>( d );
	var->set_init( e );
	return var;
}

const type* translator::on_bool_type() const
{
	return &m_cxt.bool_ty;
}

const type* translator::on_int_type() const
{
	return &m_cxt.int_ty;
}

symbol* translator::on_id( token* t )
{
	auto id = dynamic_cast<id_token*>( t );
	return id->get_name();
}
