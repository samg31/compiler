#include "expr.hpp"
#include "eval.hpp"
#include <cassert>

#include "context.hpp"
#include "check.hpp"

int main()
{
	context cxt;
	{
		bool_expr e( true, cxt );
		auto eval_test = eval_v( e );
		assert( eval_test.get_data().n == true );
	}
	{
		// constants
		bool_expr t( true, cxt );
		bool_expr f( false, cxt );

		// and expressions
		and_expr and1( t, t, cxt );
		and_expr and2( t, f, cxt );
		and_expr and3( f, f, cxt );
		assert( eval_v( and1 ).get_data().n == true );
		assert( eval_v( and2 ).get_data().n == false );
		assert( eval_v( and3 ).get_data().n == false );
		assert( check( and1 ) == &cxt.bool_ty );
	}
}
