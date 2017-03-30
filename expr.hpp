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
	virtual void visit( cond_expr& ) = 0;
	virtual void visit( equal_expr& ) = 0;
	virtual void visit( inequal_expr& ) = 0;
	virtual void visit( int_expr& ) = 0;
	virtual void visit( neg_expr& ) = 0;
	virtual void visit( add_expr& ) = 0;
	virtual void visit( sub_expr& ) = 0;
	virtual void visit( mul_expr& ) = 0;
	virtual void visit( div_expr& ) = 0;
	virtual void visit( rem_expr& ) = 0;
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

class cond_expr : public expr
{
	expr& e1;
	expr& e2;
	expr& e3;
public:
	cond_expr( expr&, expr&, expr& );
	void accept( visitor& v );
	expr& get_e1() const;
	expr& get_e2() const;
	expr& get_e3() const;
};

class equal_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	equal_expr( expr&, expr& );
	void accept( visitor& v );
	expr& get_e1() const;
	expr& get_e2() const;
};

class inequal_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	inequal_expr( expr&, expr& );
	void accept( visitor& v );
	expr& get_e1() const;
	expr& get_e2() const;
};

class int_expr : public expr
{
	int value;
public:
	int_expr( int value );
	void accept( visitor& v );
	int get_value() const;
};

class neg_expr : public expr
{
	expr& e1;
public:
	neg_expr( expr& );
	void accept( visitor& ) override;
	expr& get_e1() const;
};

class add_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	add_expr( expr&, expr& );
	void accept( visitor& );
	expr& get_e1() const;
	expr& get_e2() const;
};

class sub_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	sub_expr( expr&, expr& );
	void accept( visitor& );
	expr& get_e1() const;
	expr& get_e2() const;
};

class mul_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	mul_expr( expr&, expr& );
	void accept( visitor& );
	expr& get_e1() const;
	expr& get_e2() const;
};

class div_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	div_expr( expr&, expr& );
	void accept( visitor& );
	expr& get_e1() const;
	expr& get_e2() const;
};

class rem_expr : public expr
{
	expr& e1;
	expr& e2;
public:
	rem_expr( expr&, expr& );
	void accept( visitor& );
	expr& get_e1() const;
	expr& get_e2() const;
};

#endif
