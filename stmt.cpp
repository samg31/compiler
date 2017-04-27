#include "stmt.hpp"
#include "token.hpp"

expr_stmt::expr_stmt( expr* expression )
	:expression( expression )
{
}

decl_stmt::decl_stmt( decl* entity )
	:entity( entity )
{
}

decl* decl_stmt::get_entity() const
{
	return entity;
}

block_stmt::block_stmt( std::initializer_list<stmt*> inner_stmts )
	:stmts( inner_stmts )
{
}
