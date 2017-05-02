#include "gen.hpp"
#include "context.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "scope.hpp"

int main()
{
	using stack = std::list<scope>;
	stack stk;
	value_map vm;
	context cxt;
	std::string input = "5 + 8;";
	keyword_table kw;
	symbol_table sym;
	
	stk.emplace_front();
	lexer l( input.begin(), input.end(), kw, sym );
	parser p( l, cxt, stk, vm );
	auto v = p.statement();
	auto s = static_cast<expr_stmt*>( v );
	auto output = gen( s->expression );
	std::cout << output << '\n';
	
	return 0;
}
