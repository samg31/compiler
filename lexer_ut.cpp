#include <string>
#include <iostream>
#include <cassert>

#include "lexer.hpp"

int main()
{

	// test all punctuators/operators
	{
		std::string input;
		keyword_table kw;
		symbol_table sym;
		token* t;

		input = "% && * ()    != == = :;\t\t\n";
		input += "/ <> <= >=   ? -+ ^ !";

		lexer l( input.begin(), input.end(), kw, sym );

		t = l.next();
		assert( t->kind() == "percent" );

		t = l.next();
		assert( t->kind() == "ampersand" );
		
		t = l.next();
		assert( t->kind() == "asterix" );
		
		t = l.next();
		assert( t->kind() == "lparen" );
		
		t = l.next();
		assert( t->kind() == "rparen" );

		t = l.next();
		assert( t->kind() == "exclmeq" );

		t = l.next();
		assert( t->kind() == "eq" );
		
		t = l.next();
		assert( t->kind() == "assign" );
		
		t = l.next();
		assert( t->kind() == "colon" );
		
		t = l.next();
		assert( t->kind() == "semicolon" );

		t = l.next();
		assert( t->kind() == "slash" );
		
		t = l.next();
		assert( t->kind() == "less" );
		
		t = l.next();
		assert( t->kind() == "greater" );

		t = l.next();
		assert( t->kind() == "lesseq" );

		t = l.next();
		assert( t->kind() == "greatereq" );

		t = l.next();
		assert( t->kind() == "question" );
		
		t = l.next();
		assert( t->kind() == "minus" );

		t = l.next();
		assert( t->kind() == "plus" );

		t = l.next();
		assert( t->kind() == "caret" );

		t = l.next();
		assert( t->kind() == "exclm" );
	}

	return 0;
}
