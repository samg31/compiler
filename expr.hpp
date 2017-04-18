#ifndef EXPR_HPP
#define EXPR_HPP

#include <iostream>

#include "expr_fwd.hpp"
#include "context.hpp"

class expr
{
public:
    struct visitor;
    virtual void accept( visitor& ) = 0;
    virtual void print() { std::cout << "hello"; }
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
    virtual void visit( less_expr& ) = 0;
    virtual void visit( greater_expr& ) = 0;
    virtual void visit( lesseq_expr& ) = 0;
    virtual void visit( greatereq_expr& ) = 0;
};

class bool_expr : public expr
{
    context& cxt;
    int value;
public:
    void print() { std::cout << "bool_expr"; }
    bool_expr( int, context& );
    void accept( visitor& );
    int get_value() const;
    context& get_context() const;
};

class and_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "and_expr"; }
    and_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class or_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "or_expr"; }
    or_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class not_expr : public expr
{
    context& cxt;
    expr& e1;
public:
    void print() { std::cout << "not_expr"; }
    not_expr( expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    context& get_context() const;
};

class cond_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
    expr& e3;
public:
    void print() { std::cout << "cond_expr"; }
    cond_expr( expr&, expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    expr& get_e3() const;
    context& get_context() const;
};

class equal_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "equal_expr"; }
    equal_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class inequal_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "inequal_expr"; }
    inequal_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class int_expr : public expr
{
    context& cxt;
    int value;
public:
    void print() { std::cout << "int_expr"; }
    int_expr( int value, context& );
    void accept( visitor& );
    int get_value() const;
    context& get_context() const;
};

class neg_expr : public expr
{
    context& cxt;
    expr& e1;
public:
    void print() { std::cout << "neg_expr"; }
    neg_expr( expr&, context& );
    void accept( visitor& ) override;
    expr& get_e1() const;
    context& get_context() const;
};

class add_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "add_expr"; }
    add_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class sub_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "sub_expr"; }
    sub_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class mul_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "mul_expr"; }
    mul_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class div_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "div_expr"; }
    div_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class rem_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "rem_expr"; }
    rem_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class less_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "less_expr"; }
    less_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class greater_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "greater_expr"; }
    greater_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class lesseq_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "lesseq_expr"; }
    lesseq_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

class greatereq_expr : public expr
{
    context& cxt;
    expr& e1;
    expr& e2;
public:
    void print() { std::cout << "greatereq_expr"; }
    greatereq_expr( expr&, expr&, context& );
    void accept( visitor& );
    expr& get_e1() const;
    expr& get_e2() const;
    context& get_context() const;
};

#endif
