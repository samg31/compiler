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
