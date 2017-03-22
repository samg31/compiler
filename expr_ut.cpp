#include "expr.hpp"
#include "eval.hpp"
#include <cassert>

int main()
{
	// eval calls proper visitor
	{
		bool_expr e( true );
		int eval_test = eval( e );
		assert( eval_test == true );
	}

	// efficacy of logical expressions
	{
		// constants
		bool_expr t( true );
		bool_expr f( false );

		// and expressions
		and_expr and1( t, t );
		and_expr and2( t, f );
		and_expr and3( f, f );
		assert( eval( and1 ) == true );
		assert( eval( and2 ) == false );
		assert( eval( and3 ) == false );

		// or expressions
		or_expr or1( t, t );
		or_expr or2( t, f );
		or_expr or3( f, f );
		assert( eval( or1 ) == true );
		assert( eval( or2 ) == true );
		assert( eval( or3 ) == false );

		// not expressions
		not_expr not1( t );
		not_expr not2( f );

		assert( eval( not1 ) == false );
		assert( eval( not2 ) == true );
	}
	
	return 0;
}
