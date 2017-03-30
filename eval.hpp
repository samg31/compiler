#ifndef EVAL_HPP
#define EVAL_HPP

#include "expr.hpp"

struct eval_visitor : expr::visitor
{
	int r;
	void visit( bool_expr& e );
	void visit( and_expr& e );
	void visit( or_expr& e );
	void visit( not_expr& e );
	void visit( cond_expr& e );
	void visit( equal_expr& e );
	void visit( inequal_expr& e );
	void visit( int_expr& e );
	void visit( neg_expr& e );
	void visit( add_expr& e );
	void visit( sub_expr& e );
	void visit( mul_expr& e );
	void visit( div_expr& e );
	void visit( rem_expr& e );
};

int eval( expr& e );

#endif
