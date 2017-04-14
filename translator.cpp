#include <sstream>

#include "check.hpp"
#include "translator.hpp"

translator::translator( context& cxt )
	:m_cxt( cxt )
{
}

expr_ptr translator::on_cond( expr& ast_1, expr& ast_2, expr& ast_3 )
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
	
	return expr_ptr( new cond_expr( ast_1, ast_2, ast_3, m_cxt ) );
}

expr_ptr translator::on_or( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new or_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_and( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new and_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_equal( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != check( ast_2 ) )
	{
		std::stringstream ss;
		ss << "Expected same types in equality expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	
	return expr_ptr( new equal_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_inequal( expr& ast_1, expr& ast_2 )
{
	if( check( ast_1 ) != check( ast_2 ) )
	{
		std::stringstream ss;
		ss << "Expected same types in inequality expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}
	
	return expr_ptr( new inequal_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_less( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new less_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_greater( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new greater_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_lesseq( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new lesseq_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_greatereq( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new greatereq_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_add( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new add_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_sub( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new sub_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_mul( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new mul_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_div( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new div_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_rem( expr& ast_1, expr& ast_2 )
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

	return expr_ptr( new rem_expr( ast_1, ast_2, m_cxt ) );
}

expr_ptr translator::on_not( expr& ast_1 )
{
	if( check( ast_1 ) != &m_cxt.bool_ty )
	{
		std::stringstream ss;
		ss << "Expected bool type in not expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return expr_ptr( new not_expr( ast_1, m_cxt ) );
}

expr_ptr translator::on_neg( expr& ast_1 )
{
	if( check( ast_1 ) != &m_cxt.int_ty )
	{
		std::stringstream ss;
		ss << "Expected int type in neg expression.\n";
		throw std::runtime_error( ss.str().c_str() );
	}

	return expr_ptr( new neg_expr( ast_1, m_cxt ) );
}
