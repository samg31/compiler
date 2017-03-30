#include "check.hpp"

void check_visitor::visit( bool_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( and_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( or_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( not_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( cond_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( equal_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( inequal_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( int_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( neg_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( add_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( sub_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( mul_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( div_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( rem_expr& e )
{
	r = &e.get_context().int_ty;
}

void check_visitor::visit( less_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( greater_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( lesseq_expr& e )
{
	r = &e.get_context().bool_ty;
}

void check_visitor::visit( greatereq_expr& e )
{
	r = &e.get_context().bool_ty;
}

const type* check( expr& e )
{
	check_visitor v;
	e.accept( v );
	return v.r;
}