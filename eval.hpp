#ifndef EVAL_HPP
#define EVAL_HPP

#include "expr.hpp"

struct eval_visitor : expr::visitor
{
	int r;
	void visit( bool_expr& e );
};

int eval( expr& e );

#endif
