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

block_stmt::block_stmt( std::vector<stmt*> inner_stmts )
	:stmts( inner_stmts )
{
}

while_stmt::while_stmt( expr* condition, stmt* block )
	:condition( condition ), block( block )
{
}

expr* while_stmt::get_condition() const
{
	return condition;
}

stmt* while_stmt::get_block() const
{
	return block;
}

if_stmt::if_stmt( expr* condition, stmt* block )
	:condition( condition ), block( block )
{
}

expr* if_stmt::get_condition() const
{
	return condition;
}

stmt* if_stmt::get_block() const
{
	return block;
}
