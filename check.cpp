#include "check.hpp"

void check_visitor::visit( bool_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( and_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( or_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( not_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( cond_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( equal_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( inequal_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( int_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( neg_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( add_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( sub_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( mul_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( div_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( rem_expr* e )
{
	r = &e->get_context().int_ty;
}

void check_visitor::visit( less_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( greater_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( lesseq_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( greatereq_expr* e )
{
	r = &e->get_context().bool_ty;
}

void check_visitor::visit( ref_expr* e )
{
	r = e->get_type();
}

void check_visitor::visit( value_expr* e )
{
	auto parent = static_cast<ref_expr*>( e->get_parent() );
	r = parent->get_type();
}

void check_visitor::visit( assign_expr* e )
{

}

const type* check( expr* e )
{
	check_visitor v;
	e->accept( v );
	return v.r;
}
