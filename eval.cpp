#include "eval.hpp"
#include "decl.hpp"
#include <iostream>

void eval_visitor::visit( bool_expr* e )
{
	r = e->get_value();
}

void eval_visitor::visit( and_expr* e )
{
	int lhs = eval( e->get_e1() );
	int rhs = eval( e->get_e2() );
	r = lhs && rhs;
}

void eval_visitor::visit( or_expr* e )
{
	int lhs = eval( e->get_e1() );
	int rhs = eval( e->get_e2() );
	r = lhs || rhs;
}

void eval_visitor::visit( not_expr* e )
{
	r = !eval( e->get_e1() );
}

void eval_visitor::visit( cond_expr* e )
{
	int condition = eval( e->get_e1() );
	int lhs = eval( e->get_e2() );
	int rhs = eval( e->get_e3() );

	r = condition ? lhs : rhs;
}

void eval_visitor::visit( equal_expr* e )
{
	int lhs = eval( e->get_e1() );
	int rhs = eval( e->get_e2() );

	r = (lhs == rhs);
}

void eval_visitor::visit( inequal_expr* e )
{
	int lhs = eval( e->get_e1() );
	int rhs = eval( e->get_e2() );

	r = (lhs != rhs);
}

void eval_visitor::visit( int_expr* e )
{
	r = e->get_value();
}

void eval_visitor::visit( neg_expr* e )
{
	r = -eval( e->get_e1() );
}

void eval_visitor::visit( add_expr* e )
{
	r = eval( e->get_e1() ) +
		eval( e->get_e2() );
}

void eval_visitor::visit( sub_expr* e )
{
	r = eval( e->get_e1() ) -
		eval( e->get_e2() );	
}

void eval_visitor::visit( mul_expr* e )
{
	r = eval( e->get_e1() ) *
		eval( e->get_e2() );	
}

void eval_visitor::visit( div_expr* e )
{
	r = eval( e->get_e1() ) /
		eval( e->get_e2() );	
}

void eval_visitor::visit( rem_expr* e )
{
	r = eval( e->get_e1() ) %
		eval( e->get_e2() );	
}

void eval_visitor::visit( less_expr* e )
{
	r = eval( e->get_e1() ) <
		eval( e->get_e2() );	
}

void eval_visitor::visit( greater_expr* e )
{
	r = eval( e->get_e1() ) >
		eval( e->get_e2() );	
}

void eval_visitor::visit( lesseq_expr* e )
{
	r = eval( e->get_e1() ) <=
		eval( e->get_e2() );	
}

void eval_visitor::visit( greatereq_expr* e )
{
	r = eval( e->get_e1() ) >=
		eval( e->get_e2() );	
}

void eval_visitor::visit( ref_expr* e )
{
	r = eval( e->get_value() );
}

void eval_visitor::visit( value_expr* e )
{
	r = eval( e->get_expression() );
}

void eval_visitor::visit( assign_expr* e )
{
}

int eval( expr* e )
{
	eval_visitor v;
	e->accept( v );
	return v.r;
}

value eval_v( expr* e )
{
	eval_v_visitor v;
	e->accept( v );
	return v.r;
}

eval_v_visitor::eval_v_visitor()
	:r( value( uninit_val, value_data() ) )
{
}


void eval_v_visitor::visit( bool_expr* e )
{
	r = value( int_val, e->get_value() );
}

void eval_v_visitor::visit( and_expr* e )
{
	auto lhs = eval_v( e->get_e1() );
	auto rhs = eval_v( e->get_e2() );
	r = value( int_val, lhs.get_data().n && rhs.get_data().n );
}

void eval_v_visitor::visit( or_expr* e )
{
	auto lhs = eval_v( e->get_e1() );
	auto rhs = eval_v( e->get_e2() );
	r = value( int_val, lhs.get_data().n || rhs.get_data().n );
}

void eval_v_visitor::visit( not_expr* e )
{
	r = value( int_val, !eval_v( e->get_e1() ).get_data().n );
}

void eval_v_visitor::visit( cond_expr* e )
{
	auto condition = eval_v( e->get_e1() );
	auto lhs = eval_v( e->get_e2() );
	auto rhs = eval_v( e->get_e3() );

	r = value( int_val, condition.get_data().n ? lhs.get_data().n : rhs.get_data().n );
}

void eval_v_visitor::visit( equal_expr* e )
{
	auto lhs = eval_v( e->get_e1() );
	auto rhs = eval_v( e->get_e2() );

	r = value(int_val, lhs.get_data().n == rhs.get_data().n);
}

void eval_v_visitor::visit( inequal_expr* e )
{
	auto lhs = eval_v( e->get_e1() );
	auto rhs = eval_v( e->get_e2() );

	r = value(int_val, lhs.get_data().n != rhs.get_data().n);
}

void eval_v_visitor::visit( int_expr* e )
{
	r = value( int_val, e->get_value() );
}

void eval_v_visitor::visit( neg_expr* e )
{
	r = value( int_val, -eval_v( e->get_e1() ).get_data().n );
}

void eval_v_visitor::visit( add_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n +
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( sub_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n -
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( mul_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n *
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( div_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n /
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( rem_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n %
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( less_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n <
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( greater_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n >
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( lesseq_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n <=
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( greatereq_expr* e )
{
	r = value( int_val, eval_v( e->get_e1() ).get_data().n >=
			   eval_v( e->get_e2() ).get_data().n );
}

void eval_v_visitor::visit( ref_expr* e )
{

}

void eval_v_visitor::visit( value_expr* e )
{
	// auto ref = static_cast<var_decl*>( e->get_reference().get_reference() );
	// auto expression = ref->m_init;

	// eval_v( *expression );
}

void eval_v_visitor::visit( assign_expr*  e )
{
}
