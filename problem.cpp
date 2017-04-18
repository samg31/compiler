// this program illustrates a problem with returning unique_ptrs of base classes
// particularly, if the object being assigned to is used as an argument in a function,
// it seems as though it is demoted to a base pointer after being returned. it cannot
// access any of the member variables or methods of the derived class.

#include "expr.hpp"
#include "eval.hpp"
#include <iostream>
#include <memory>

using expr_ptr = std::unique_ptr<expr>;

// create an add_expr 
expr_ptr create( expr_ptr& ast1, expr_ptr& ast2, context& cxt );

int main()
{
	context x;
	auto e1 = expr_ptr( std::make_unique<int_expr>( 5, x ) );
	auto e2 = expr_ptr( std::make_unique<int_expr>( 10, x ) );
	
	e1 = create( e1, e2, x );

	// after returning from the function, print and eval no longer work.
	// using the print function or attempting to evaluate both result
	// in a segfault
	e1->print();
	std::cout << eval( *e1 ) << '\n';

	// when creating a new object like this; print and eval work properly
	// auto e3 = create( e1, e2, x );
	// e3->print();
	// std::cout << '\n';
	// std::cout << eval( *e3 ) << '\n';
	
}

expr_ptr create( expr_ptr& ast1, expr_ptr& ast2, context& cxt )
{
    auto r = expr_ptr( std::make_unique<add_expr>( *ast1, *ast2, cxt ) );

    // here r is recognized as an add_expr and evaluates properly
    r->print();
    std::cout << '\n';
    std::cout << eval( *r ) << '\n';
    return r;
}
