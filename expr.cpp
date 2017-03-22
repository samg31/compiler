#include "expr.hpp"

bool_expr::bool_expr( int value )
	:value( value )
{
}

void bool_expr::accept( visitor& v )
{
	v.visit( this );
}

int bool_expr::get_value() const
{
	return value;
}
