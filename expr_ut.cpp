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

		// conditional expressions
		cond_expr cond1( t, t, f );
		cond_expr cond2( f, t, f );
		assert( eval( cond1 ) == true );
		assert( eval( cond2 ) == false );

		// equality expressions
		equal_expr equal1( t, t );
		equal_expr equal2( t, f );
		assert( eval( equal1 ) == true );
		assert( eval( equal2 ) == false );

		// inequality expressions
		inequal_expr inequal1( t, t );
		inequal_expr inequal2( t, f );
		assert( eval( inequal1 ) == false );
		assert( eval( inequal2 ) == true );
	}

	// int_expr efficacy
	{
		int_expr int1( 43 );
		assert( eval( int1 ) == 43 );
	}

	// neg_expr efficacy
	{
		int_expr int1( 43 );
		neg_expr neg1( int1 );
		assert( eval( neg1 ) == -43 );
	}

	// efficacy of add_expr and sub_expr
	{
		int_expr int1( 100 );
		int_expr int2( 50 );
		neg_expr neg1( int1 );

		add_expr add1( int1, int2 );
		add_expr add2( int1, neg1 );
		assert( eval( add1 ) == 150 );
		assert( eval( add2 ) == 0 );

		sub_expr sub1( int1, int2 );
		sub_expr sub2( int1, neg1 );
		assert( eval( sub1 ) == -50 );
		assert( eval( sub2 ) == 200 );
	}
	
	return 0;
}
