#ifndef STMT_HPP
#define STMT_HPP

#include <vector>
#include <initializer_list>

#include "decl.hpp"

class stmt
{
public:
	virtual ~stmt() = default;
};

class expr_stmt : public stmt
{
public:	
	expr* expression;
	expr_stmt( expr* );
};

class decl_stmt : public stmt
{
public:
	decl* entity;
	decl* get_entity() const;
	decl_stmt( decl* );
};

class block_stmt : public stmt
{
	std::vector<stmt*> stmts;
public:
	block_stmt( std::initializer_list<stmt*> );
	block_stmt( std::vector<stmt*> );
};

class while_stmt : public stmt
{
	expr* condition;
	stmt* block;
public:
	while_stmt( expr*, stmt*  );
	expr* get_condition() const;
	stmt* get_block() const;
};

class if_stmt : public stmt
{
	expr* condition;
	stmt* block;
public:
	if_stmt( expr*, stmt*  );
	expr* get_condition() const;
	stmt* get_block() const;
};
#endif
