#ifndef LEXER_HPP
#define LEXER_HPP

#include <queue>
#include <memory>

#include "token.hpp"
#include "symbol.hpp"

using token_ptr = std::unique_ptr<token>;

class lexer
{
    std::string::iterator first;
    std::string::iterator last;
	keyword_table& kw;
	symbol_table& sym;    
    std::string buf;

	std::queue<token_ptr> tokens;

public:
	
    lexer( std::string::iterator first, std::string::iterator last,
		   keyword_table& kw, symbol_table& sym );
    bool eof() const;
    char consume();
    char ignore();
    char lookahead();
    void lex();
	token_ptr front();

	void word();
	void number();
};
	
#endif
