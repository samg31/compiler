#ifndef EXPR_HPP
#define EXPR_HPP

#include <iostream>

#include "expr_fwd.hpp"
#include "context.hpp"

class decl;

class expr
{
public:
    struct visitor;
    virtual void accept( visitor& ) = 0;
    virtual ~expr() = default;
};

struct expr::visitor
{
    virtual void visit( bool_expr* ) = 0;
    virtual void visit( and_expr* ) = 0;
    virtual void visit( or_expr* ) = 0;
    virtual void visit( not_expr* ) = 0;
    virtual void visit( cond_expr* ) = 0;
    virtual void visit( equal_expr* ) = 0;
    virtual void visit( inequal_expr* ) = 0;
    virtual void visit( int_expr* ) = 0;
    virtual void visit( neg_expr* ) = 0;
    virtual void visit( add_expr* ) = 0;
    virtual void visit( sub_expr* ) = 0;
    virtual void visit( mul_expr* ) = 0;
    virtual void visit( div_expr* ) = 0;
    virtual void visit( rem_expr* ) = 0;
    virtual void visit( less_expr* ) = 0;
    virtual void visit( greater_expr* ) = 0;
    virtual void visit( lesseq_expr* ) = 0;
    virtual void visit( greatereq_expr* ) = 0;
	virtual void visit( ref_expr* ) = 0;
	virtual void visit( value_expr* ) = 0;
	virtual void visit( assign_expr* ) = 0;
};

class bool_expr : public expr
{
    context& cxt;
    int value;
public:
    bool_expr( int, context& );
    void accept( visitor& );
    int get_value() const;
    context& get_context() const;
};

class and_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    and_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class or_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    or_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class not_expr : public expr
{
    context& cxt;
    expr* e1;
public:
    not_expr( expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    context& get_context() const;
};

class cond_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
    expr* e3;
public:
    cond_expr( expr*, expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    expr* get_e3() const;
    context& get_context() const;
};

class equal_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    equal_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class inequal_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    inequal_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class int_expr : public expr
{
    context& cxt;
    int value;
public:
    int_expr( int value, context& );
    void accept( visitor& );
    int get_value() const;
    context& get_context() const;
};

class neg_expr : public expr
{
    context& cxt;
    expr* e1;
public:
    neg_expr( expr*, context& );
    void accept( visitor& ) override;
    expr* get_e1() const;
    context& get_context() const;
};

class add_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    add_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class sub_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    sub_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class mul_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    mul_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class div_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    div_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class rem_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    rem_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class less_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    less_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class greater_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    greater_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class lesseq_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    lesseq_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class greatereq_expr : public expr
{
    context& cxt;
    expr* e1;
    expr* e2;
public:
    greatereq_expr( expr*, expr*, context& );
    void accept( visitor& );
    expr* get_e1() const;
    expr* get_e2() const;
    context& get_context() const;
};

class ref_expr : public expr
{
public:
	context& cxt;
	decl* reference;
	value_expr* val;
	const type* m_type;
public:
	ref_expr( decl*, expr*, const type*, context& );
	decl* get_reference() const;
	value_expr* get_value() const;
	const type* get_type() const;
	context& get_context() const;
	void set_value( expr* );
	void accept( visitor& );
};

class value_expr : public expr
{
	context& cxt;
	expr* e;
	expr* parent;
public:
	value_expr( expr*, context& );
	expr* get_expression() const;
	expr* get_parent() const;
	void set_parent( expr* );
	void accept( visitor& );
};

class assign_expr : public expr
{
	ref_expr* m_reference;
	expr* m_new_value;
public:
	assign_expr( ref_expr*, expr* );
	ref_expr* get_reference() const;
	expr* get_value() const;
	void accept( visitor& );
};

#endif
