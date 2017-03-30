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
