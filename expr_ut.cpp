#include "expr.hpp"
#include "eval.hpp"
#include <cassert>

int main()
{
	// test that eval calls proper visitor
	{
		bool_expr e( true );
		int eval_test = eval( e );
		assert( eval_test == true );
	}
	
	return 0;
}
