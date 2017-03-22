#include "eval.hpp"

void eval_visitor::visit( bool_expr& e )
{
	r = e.get_value();
}

void eval_visitor::visit( and_expr& e )
{
	int lhs = eval( e.get_e1() );
	int rhs = eval( e.get_e2() );
	r = lhs && rhs;
}

void eval_visitor::visit( or_expr& e )
{
	// int lhs = eval( e.get_e1() );
	// int rhs = eval( e.get_e2() );
	// r = lhs && rhs;
}

int eval( expr& e )
{
	eval_visitor v;
	e.accept( v );
	return v.r;
}
