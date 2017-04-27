#include "expr.hpp"
#include "context.hpp"

bool_expr::bool_expr( int value, context& cxt )
	:value( value ), cxt( cxt )
{
}

void bool_expr::accept( visitor& v )
{
	v.visit( *this );
}

int bool_expr::get_value() const
{
	return value;
}

context& bool_expr::get_context() const
{
	return cxt;
}

and_expr::and_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void and_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& and_expr::get_e1() const
{
	return e1;
}

expr& and_expr::get_e2() const
{
	return e2;
}

context& and_expr::get_context() const
{
	return cxt;
}

or_expr::or_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void or_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& or_expr::get_e1() const
{
	return e1;
}

expr& or_expr::get_e2() const
{
	return e2;
}

context& or_expr::get_context() const
{
	return cxt;
}

not_expr::not_expr( expr& e1, context& cxt )
	:e1(e1), cxt( cxt )
{
}

void not_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& not_expr::get_e1() const
{
	return e1;
}

context& not_expr::get_context() const
{
	return cxt;
}

cond_expr::cond_expr( expr& e1, expr& e2,
					  expr& e3, context& cxt )
	:e1( e1 ), e2( e2 ), e3( e3 ), cxt( cxt )
{
}

void cond_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& cond_expr::get_e1() const
{
	return e1;
}

expr& cond_expr::get_e2() const
{
	return e2;
}

expr& cond_expr::get_e3() const
{
	return e3;
}

context& cond_expr::get_context() const
{
	return cxt;
}

equal_expr::equal_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void equal_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& equal_expr::get_e1() const
{
	return e1;
}

expr& equal_expr::get_e2() const
{
	return e2;
}

context& equal_expr::get_context() const
{
	return cxt;
}

inequal_expr::inequal_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void inequal_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& inequal_expr::get_e1() const
{
	return e1;
}

expr& inequal_expr::get_e2() const
{
	return e2;
}

context& inequal_expr::get_context() const
{
	return cxt;
}

int_expr::int_expr( int value, context& cxt )
	:value( value ), cxt( cxt )
{
}

int int_expr::get_value() const
{
	return value;
}

void int_expr::accept( visitor& v )
{
	v.visit( *this );
}

context& int_expr::get_context() const
{
	return cxt;
}

neg_expr::neg_expr( expr& e, context& cxt )
	:e1( e ), cxt( cxt )
{
}

void neg_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& neg_expr::get_e1() const
{
	return e1;
};

context& neg_expr::get_context() const
{
	return cxt;
}

add_expr::add_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void add_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& add_expr::get_e1() const
{
	return e1;
}

expr& add_expr::get_e2() const
{
	return e2;
}

context& add_expr::get_context() const
{
	return cxt;
}

sub_expr::sub_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void sub_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& sub_expr::get_e1() const
{
	return e1;
}

expr& sub_expr::get_e2() const
{
	return e2;
}

context& sub_expr::get_context() const
{
	return cxt;
}

mul_expr::mul_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void mul_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& mul_expr::get_e1() const
{
	return e1;
}

expr& mul_expr::get_e2() const
{
	return e2;
}

context& mul_expr::get_context() const
{
	return cxt;
}

div_expr::div_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void div_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& div_expr::get_e1() const
{
	return e1;
}

expr& div_expr::get_e2() const
{
	return e2;
}

context& div_expr::get_context() const
{
	return cxt;
}

rem_expr::rem_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void rem_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& rem_expr::get_e1() const
{
	return e1;
}

expr& rem_expr::get_e2() const
{
	return e2;
}

context& rem_expr::get_context() const
{
	return cxt;
}

less_expr::less_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void less_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& less_expr::get_e1() const
{
	return e1;
}

expr& less_expr::get_e2() const
{
	return e2;
}

context& less_expr::get_context() const
{
	return cxt;
}

greater_expr::greater_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void greater_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& greater_expr::get_e1() const
{
	return e1;
}

expr& greater_expr::get_e2() const
{
	return e2;
}

context& greater_expr::get_context() const
{
	return cxt;
}

lesseq_expr::lesseq_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void lesseq_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& lesseq_expr::get_e1() const
{
	return e1;
}

expr& lesseq_expr::get_e2() const
{
	return e2;
}

context& lesseq_expr::get_context() const
{
	return cxt;
}

greatereq_expr::greatereq_expr( expr& e1, expr& e2, context& cxt )
	:e1( e1 ), e2( e2 ), cxt( cxt )
{
}

void greatereq_expr::accept( visitor& v )
{
	v.visit( *this );
}

expr& greatereq_expr::get_e1() const
{
	return e1;
}

expr& greatereq_expr::get_e2() const
{
	return e2;
}

context& greatereq_expr::get_context() const
{
	return cxt;
}

ref_expr::ref_expr( decl* reference, expr* ref_val, const type* ty, context& cxt )
	:reference( reference ), cxt( cxt ),
	 val( new value_expr( ref_val, cxt ) ), m_type( ty )
{
	val->set_parent( this );
}

decl* ref_expr::get_reference() const
{
	return reference;
}

value_expr* ref_expr::get_value() const
{
	return val;
}

const type* ref_expr::get_type() const
{
	return m_type;
}

context& ref_expr::get_context() const
{
	return cxt;
}

void ref_expr::set_value( expr* new_value )
{
	auto temp = val;
	val = new value_expr( new_value, cxt );
	delete temp;
}

void ref_expr::accept( visitor& v )
{
	v.visit( *this );
}

value_expr::value_expr( expr* val, context& cxt )
	:e( val ), cxt( cxt )
{
}

expr* value_expr::get_expression() const
{
	return e;
}

expr* value_expr::get_parent() const
{
	return parent;
}

void value_expr::set_parent( expr* p )
{
	parent = p;
}

void value_expr::accept( visitor& v )
{
	v.visit( *this );
}
