#include "lexer.hpp"
#include <cctype>

lexer::lexer( std::string::iterator first, std::string::iterator last,
	   keyword_table& kw, symbol_table& sym )
	:first( first ), last( last ), kw( kw ), sym( sym )
{
}

bool lexer::eof() const
{
	return first == last;
}

char lexer::consume()
{
	if( eof() )
		return 0;
	buf += *first++;
	return buf.back();	
}

char lexer::ignore()
{
	return ( eof() ) ? 0 : *first++;	
}

char lexer::lookahead()
{
	return ( eof() ) ? 0 : *first;	
}

token* lexer::next()
{
	token* r = nullptr;
	buf.clear();
	while( !eof() )
	{
		switch( lookahead() )
		{
		case '(':
			consume();
			r = new punc_token( lparen_tok );
			break;
		case ')':
			consume();
			r = new punc_token( rparen_tok );
			break;
		case '&':
			consume();
			if( lookahead() == '&' )
			{
				consume();
				r = new punc_token( ampersand_tok );
			}
			break;
		case '|':
			consume();		
			if( lookahead() == '|' )
			{
				consume();
				r = new punc_token( bar_tok );
			}
			break;
		case '^':
			consume();
			r = new punc_token( caret_tok );
			break;
		case '!':
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = new punc_token( exclmeq_tok );
			}
			r = new punc_token( exclm_tok );
			break;
		case '+':
			consume();
			r = new punc_token( plus_tok );
			break;
		case '-':
			consume();
			r = new punc_token( minus_tok );
			break;
		case '*':
			consume();
			r = new punc_token( asterix_tok );
			break;
		case '/':
			consume();
			r = new punc_token( slash_tok );
			break;
		case '%':
			consume();
			r = new punc_token( percent_tok );
			break;
		case '?':
			consume();
			r = new punc_token( question_tok );
			break;
		case ':':
			consume();
			r = new punc_token( colon_tok );
			break;
		case ';':
			consume();
			r = new punc_token( semicolon_tok );
			break;
		case '<':
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = new punc_token( lesseq_tok );
			}
			else
				r = new punc_token( less_tok );
			break;
		case '>':
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = new punc_token( greatereq_tok );
			}
			else
				r = new punc_token( greater_tok );
			break;
		case '=':
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = new punc_token( equal_tok );
			}
			else
				r = new punc_token( assign_tok );
			break;
		case '#':
			while( lookahead() != '\n' )
			{
				ignore();
			}
		case ' ':
		case '\t':
		case '\n':
			ignore();
			continue;
		default:
			if( std::isalpha( lookahead() ) )
			{				
				do
				{
					consume();
				} while( std::isalpha( lookahead() ) || std::isdigit( lookahead() ) );

				auto iter = kw.find( buf );

				if( iter != kw.end() )
				{
					if( iter->first == "true" ||
						iter->first == "false" )
						r = new bool_token( iter->second );
					else
						r = new punc_token( iter->second );
				}
				else
				{
					// add new term to symbol table
					auto name = sym.insert( buf );
					r = new id_token( *name );
				}
			}
			else if( std::isdigit( lookahead() ) )
			{
				do
				{
					consume();
				} while( !eof() && std::isdigit( lookahead() ) );
				int n = std::stoi( buf );
				token* t = new int_token( n );
				r = t;
			}

			throw std::runtime_error( "unknown token encountered\n" );
		}
	}
	return r;
}
