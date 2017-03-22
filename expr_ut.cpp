#include "expr.hpp"
#include "eval.hpp"
#include <cassert>

int main()
{
	{
		expr* e = new bool_expr( true );
		int eval_test = eval( e );
		assert( eval_test == true );
	}
	return 0;
}
