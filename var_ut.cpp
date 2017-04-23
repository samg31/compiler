#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

#include "expr.hpp"
#include "context.hpp"
#include "eval.hpp"
#include "check.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "stmt.hpp"

int main()
{
	context context;
	keyword_table kw;
	symbol_table sym;

	bool quit = false;

	while( !quit )
	{
		std::string input;
		std::string line;
		getline(std::cin, line);
		input += line + '\n';
		lexer l ( input.begin(), input.end(), kw, sym );

		parser p( l, context );
		stmt* s = p.statement();
		if( dynamic_cast<expr_stmt*>(s) )
		{
			expr_stmt* exst = dynamic_cast<expr_stmt*>( s );			
			std::cout << eval(*exst->expression) << '\n';
		}
		else if( dynamic_cast<decl_stmt*>(s) )
		{
			decl_stmt* d = dynamic_cast<decl_stmt*>( s );
			var_decl* v = dynamic_cast<var_decl*>( d->entity );
			std::cout << eval(*v->m_init) << '\n';
		}

	}

	return 0;
}
