#ifndef EVAL_HPP
#define EVAL_HPP

#include "expr.hpp"

int eval( expr* e )
{
	struct eval_visitor : expr::visitor
	{
		int r;
		void visit( bool_expr* e ) { r = e->get_value(); }
	};

	eval_visitor v;
	e->accept( v );
	return v.r;
}

#endif
