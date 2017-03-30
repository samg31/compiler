#include "expr.hpp"
#include "eval.hpp"
#include <cassert>

#include "context.hpp"
#include "check.hpp"

int main()
{
	context cxt;
	// eval calls proper visitor
	{
		bool_expr e( true, cxt );
		int eval_test = eval( e );
		assert( eval_test == true );
		assert( check( e ) == &cxt.bool_ty );
	}

	// efficacy of logical expressions
	{
		// constants
		bool_expr t( true, cxt );
		bool_expr f( false, cxt );

		// and expressions
		and_expr and1( t, t, cxt );
		and_expr and2( t, f, cxt );
		and_expr and3( f, f, cxt );
		assert( eval( and1 ) == true );
		assert( eval( and2 ) == false );
		assert( eval( and3 ) == false );
		assert( check( and1 ) == &cxt.bool_ty );

		// or expressions
		or_expr or1( t, t, cxt );
		or_expr or2( t, f, cxt );
		or_expr or3( f, f, cxt );
		assert( eval( or1 ) == true );
		assert( eval( or2 ) == true );
		assert( eval( or3 ) == false );
		assert( check( or1 ) == &cxt.bool_ty );
		
		// not expressions
		not_expr not1( t, cxt );
		not_expr not2( f, cxt );
		assert( eval( not1 ) == false );
		assert( eval( not2 ) == true );
		assert( check( not1 ) == &cxt.bool_ty );

		// conditional expressions
		cond_expr cond1( t, t, f, cxt );
		cond_expr cond2( f, t, f, cxt );
		assert( eval( cond1 ) == true );
		assert( eval( cond2 ) == false );
		assert( check( cond1 ) == &cxt.bool_ty );
		
		// equality expressions
		equal_expr equal1( t, t, cxt );
		equal_expr equal2( t, f, cxt );
		assert( eval( equal1 ) == true );
		assert( eval( equal2 ) == false );
		assert( check( equal1 ) == &cxt.bool_ty );

		// inequality expressions
		inequal_expr inequal1( t, t, cxt );
		inequal_expr inequal2( t, f, cxt );
		assert( eval( inequal1 ) == false );
		assert( eval( inequal2 ) == true );
		assert( check( inequal1 ) == &cxt.bool_ty );
	}

	// int_expr efficacy
	{
		int_expr int1( 43, cxt );
		assert( eval( int1 ) == 43 );
		assert( check( int1 ) == &cxt.int_ty );
	}

	// neg_expr efficacy
	{
		int_expr int1( 43, cxt );
		neg_expr neg1( int1, cxt );
		assert( eval( neg1 ) == -43 );
		assert( check( neg1 ) == &cxt.int_ty );
	}

	// efficacy of add_expr and sub_expr
	{
		int_expr int1( 100, cxt );
		int_expr int2( 50, cxt );
		neg_expr neg1( int1, cxt );

		add_expr add1( int1, int2, cxt );
		add_expr add2( int1, neg1, cxt );
		assert( eval( add1 ) == 150 );
		assert( eval( add2 ) == 0 );
		assert( check( add1 ) == &cxt.int_ty );

		sub_expr sub1( int1, int2, cxt );
		sub_expr sub2( int1, neg1, cxt );
		assert( eval( sub1 ) == 50 );
		assert( eval( sub2 ) == 200 );
		assert( check( sub1 ) == &cxt.int_ty );
	}

	// mul_expr and div_expr
	{
		int_expr int1( 100, cxt );
		int_expr int2( 50, cxt );
		
		mul_expr mul1( int1, int2, cxt );
		assert( eval( mul1 ) == 5000 );
		assert( check( mul1 ) == &cxt.int_ty );

		div_expr div1( int1, int2, cxt );
		assert( eval( div1 ) == 2 );
		assert( check( div1 ) == &cxt.int_ty );

		rem_expr rem1( int1, int2, cxt );
		assert( eval( rem1 ) == 0 );
		assert( check( rem1 ) == &cxt.int_ty );
	}

	// relational expressions
	{
		int_expr int1( 100, cxt );
		int_expr int2( 50, cxt );

		less_expr l1 ( int1, int2, cxt );
		less_expr l2 ( int2, int1, cxt );
		assert( eval( l1 ) == false );
		assert( eval( l2 ) == true );
		assert( check( l1 ) == &cxt.bool_ty );

		greater_expr g1( int1, int2, cxt );
		greater_expr g2( int2, int1, cxt );
		assert( eval( g1 ) == true );
		assert( eval( g2 ) == false );
		assert( check( g1 ) == &cxt.bool_ty );

		lesseq_expr le1( int1, int2, cxt );
		lesseq_expr le2( int2, int1, cxt );
		lesseq_expr le3( int1, int1, cxt );
		assert( eval( le1 ) == false );
		assert( eval( le2 ) == true );
		assert( eval( le3 ) == true );
		assert( check( le1 ) == &cxt.bool_ty );
		
		greatereq_expr ge1( int1, int2, cxt );
		greatereq_expr ge2( int2, int1, cxt );
		greatereq_expr ge3( int1, int1, cxt );
		assert( eval( ge1 ) == true );
		assert( eval( ge2 ) == false );
		assert( eval( ge3 ) == true );
		assert( check( ge1 ) == &cxt.bool_ty );
		
	}
	
	return 0;
}
