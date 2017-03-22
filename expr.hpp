#ifndef EXPR_HPP
#define EXPR_HPP

#include "expr_fwd.hpp"

class expr
{
public:
	struct visitor;
	virtual void accept( visitor& v ) = 0;
	virtual ~expr() = default;
};

struct expr::visitor
{
	virtual void visit( bool_expr& ) = 0;
	virtual void visit( and_expr& ) = 0;
	virtual void visit( or_expr& ) = 0;
	virtual void visit( not_expr& ) = 0;
};

class bool_expr : public expr
{
	int value;
public:
	bool_expr( int value );
	void accept( visitor& v );
	int get_value() const;
};

class and_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	and_expr( expr& e1, expr& e2 );
	void accept( visitor& v );
	expr& get_e1() const;
	expr& get_e2() const;
};

class or_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	or_expr( expr& e1, expr& e2 );
	void accept( visitor& v );
	expr& get_e1() const;
	expr& get_e2() const;
};

class not_expr : public expr
{
	expr& e1;
public:
	not_expr( expr& e1 );
	void accept( visitor& v );
	expr& get_e1() const;
};

#endif
