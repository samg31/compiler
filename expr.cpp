#include "expr.hpp"

bool_expr::bool_expr( int value )
	:value( value )
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

and_expr::and_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

or_expr::or_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

not_expr::not_expr( expr& e1 )
	:e1(e1)
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

cond_expr::cond_expr( expr& e1, expr& e2, expr& e3 )
	:e1( e1 ), e2( e2 ), e3( e3 )
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

equal_expr::equal_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

inequal_expr::inequal_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

int_expr::int_expr( int value )
	:value( value )
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

neg_expr::neg_expr( expr& e )
	:e1( e )
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

add_expr::add_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

sub_expr::sub_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

mul_expr::mul_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

div_expr::div_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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

rem_expr::rem_expr( expr& e1, expr& e2 )
	:e1( e1 ), e2( e2 )
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
