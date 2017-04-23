#ifndef STMT_HPP
#define STMT_HPP

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
	decl_stmt( decl* );
};

#endif
