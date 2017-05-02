#include "gen.hpp"
#include "eval.hpp"

void gen_visitor::visit( bool_expr* e )
{
}

void gen_visitor::visit( and_expr* e )
{
}

void gen_visitor::visit( or_expr* e )
{
}

void gen_visitor::visit( not_expr* e )
{
}

void gen_visitor::visit( cond_expr* e )
{
}

void gen_visitor::visit( equal_expr* e )
{
}

void gen_visitor::visit( inequal_expr* e )
{
}

void gen_visitor::visit( int_expr* e )
{
	r += "  bipush " + std::to_string( eval( e ) ) + "\n";
}

void gen_visitor::visit( neg_expr* e )
{
	r += gen( e->get_e1() );
	r += "  ineg\n";
}

void gen_visitor::visit( add_expr* e )
{
	r += gen( e->get_e1() );
	r += gen( e->get_e2() );
	r += "  iadd\n";
}

void gen_visitor::visit( sub_expr* e )
{
	r += gen( e->get_e1() );
	r += gen( e->get_e2() );
	r += "  isub\n";
}

void gen_visitor::visit( mul_expr* e )
{
	r += gen( e->get_e1() );
	r += gen( e->get_e2() );
	r += "  imul\n";
}

void gen_visitor::visit( div_expr* e )
{
	r += gen( e->get_e1() );
	r += gen( e->get_e2() );
	r += "  idiv\n";
}

void gen_visitor::visit( rem_expr* e )
{
	r += gen( e->get_e1() );
	r += gen( e->get_e2() );
	r += "  irem\n";
}

void gen_visitor::visit( less_expr* e )
{
}

void gen_visitor::visit( greater_expr* e )
{
}

void gen_visitor::visit( lesseq_expr* e )
{
}

void gen_visitor::visit( greatereq_expr* e )
{
}

void gen_visitor::visit( ref_expr* e )
{
}

void gen_visitor::visit( value_expr* e )
{
}

void gen_visitor::visit( assign_expr* e )
{
	
}

std::string gen( expr* e )
{
	gen_visitor v;
	e->accept( v );
	return v.r;
}
