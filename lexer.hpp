#ifndef LEXER_HPP
#define LEXER_HPP

#include "token.hpp"
#include "symbol.hpp"

class lexer
{

    std::string::iterator first;
    std::string::iterator last;
	keyword_table& kw;
	symbol_table& sym;    
    std::string buf;

public:
	
    lexer( std::string::iterator first, std::string::iterator last,
		   keyword_table& kw, symbol_table& sym );
    bool eof() const;
    char consume();
    char ignore();
    char lookahead();
    token* next();
};
	
#endif
