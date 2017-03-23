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
	int lhs = eval( e.get_e1() );
	int rhs = eval( e.get_e2() );
	r = lhs || rhs;
}

void eval_visitor::visit( not_expr& e )
{
	r = !eval( e.get_e1() );
}

void eval_visitor::visit( cond_expr& e )
{
	int condition = eval( e.get_e1() );
	int lhs = eval( e.get_e2() );
	int rhs = eval( e.get_e3() );

	r = condition ? lhs : rhs;
}

void eval_visitor::visit( equal_expr& e )
{
	int lhs = eval( e.get_e1() );
	int rhs = eval( e.get_e2() );

	r = (lhs == rhs);
}

void eval_visitor::visit( inequal_expr& e )
{
	int lhs = eval( e.get_e1() );
	int rhs = eval( e.get_e2() );

	r = (lhs != rhs);
}

void eval_visitor::visit( int_expr& e )
{
	r = e.get_value();
}

void eval_visitor::visit( neg_expr& e )
{
}

int eval( expr& e )
{
	eval_visitor v;
	e.accept( v );
	return v.r;
}
