#include "parser.hpp"
#include "expr.hpp"
#include "eval.hpp"
#include <iostream>

std::unique_ptr<expr> create( expr& ast1, expr& ast2, context& cxt );

int main()
{
	// std::string input;
	// symbol_table sym;
	// keyword_table kw;
	// context cxt;

	// getline( std::cin, input );
	// lexer l( input.begin(), input.end(), kw, sym );
	// parser p( l, cxt );
	
	// while( true )
	// {
	// 	auto e = p.expression();
	// 	std::cout << eval( *e ) << '\n';
	// 	break;
	// }
	context x;
	std::unique_ptr<expr> e1 = std::unique_ptr<expr>( new int_expr( 5, x ) );
	std::unique_ptr<expr> e2 = std::unique_ptr<expr>( new int_expr( 10, x ) );
	e1 = create( *e1, *e2, x );
	auto y = static_cast<add_expr&>( *e1 );
	std::cout << "ok\n";
	std::cout << eval( y ) << '\n';
	
}

std::unique_ptr<expr> create( expr& ast1, expr& ast2, context& cxt )
{
	auto r = std::unique_ptr<expr>( new add_expr( ast1, ast2, cxt ) );
	std::cout << eval( *r ) << '\n';
	return r;
}
