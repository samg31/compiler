#include <string>
#include <iostream>
#include <cassert>
#include <cctype>

#include "lexer.hpp"

void test1();
void test2();

int main()
{

	// test all punctuators/operators
	test1();
	
	// test keywords
 	test2();
	
	return 0;
}

void test1()
{
	std::string input;
	keyword_table kw;
	symbol_table sym;
	token_ptr t;

	input = "% && * ()    != == = :;\t\t\n";
	input += "/ <> <= >=   ? -+ ^ !";

	input = "false && false";

	lexer l( input.begin(), input.end(), kw, sym );

	l.lex();
	while( t = std::move( l.front() ) )
	{
		std::cout << t->kind() << '\n';
		std::cout << t->print_value() << '\n';
	}
}
	
void test2()
{
	std::string input;
	keyword_table kw;
	symbol_table sym;
	token* t;

	input = "true false var int bool";
		
	lexer l( input.begin(), input.end(), kw, sym );

	// t = l.next();
	// assert( t->kind() == "true_kw" );

	// t = l.next();
	// assert( t->kind() == "false_kw" );
		
	// t = l.next();
	// assert( t->kind() == "var_kw" );
		
	// t = l.next();
	// assert( t->kind() == "int_kw" );

	// t = l.next();
	// assert( t->kind() == "bool_kw" );
}
