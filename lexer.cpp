#include "lexer.hpp"
#include <cctype>
#include <iostream>

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

void lexer::lex()
{
	token_ptr r = nullptr;
	while( !eof() )
	{
		buf.clear();
		switch( lookahead() )
		{
		case '(':
		{
			consume();
			r = token_ptr( new punc_token( lparen_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case ')':
		{
			consume();
			r = token_ptr( new punc_token( rparen_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '{':
		{
			consume();
			r = token_ptr( new punc_token( lbrace_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '}':
		{
			consume();
			r = token_ptr( new punc_token( rbrace_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '&':
		{
			consume();
			if( lookahead() == '&' )
			{
				consume();
				r = token_ptr( new punc_token( ampersand_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				throw std::runtime_error( "invalid token after '&'" );
			}			
			break;
		}
		case '|':
		{
			consume();		
			if( lookahead() == '|' )
			{
				consume();
				r = token_ptr( new punc_token( bar_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				throw std::runtime_error( "invalid token after '|'" );
			}
			break;
		}
		case '^':
		{
			consume();
			r = token_ptr( new punc_token( caret_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '!':
		{
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = token_ptr( new punc_token( exclmeq_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				r = token_ptr( new punc_token( exclm_tok ) );
				tokens.push( std::move( r ) );
			}
			break;
		}
		case '+':
		{
			consume();
			r = token_ptr( new punc_token( plus_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '-':
		{
			consume();
			if( lookahead() == '>' )
			{
				consume();
				r = token_ptr( new punc_token( arrow_tok ) );
			}
			r = token_ptr( new punc_token( minus_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '*':
		{
			consume();
			r = token_ptr( new punc_token( asterix_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '/':
		{
			consume();
			r = token_ptr( new punc_token( slash_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '%':
		{
			consume();
			r = token_ptr( new punc_token( percent_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '?':
		{
			consume();
			r = token_ptr( new punc_token( question_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case ':':
		{
			consume();
			r = token_ptr( new punc_token( colon_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case ';':
		{
			consume();
			r = token_ptr( new punc_token( semicolon_tok ) );
			tokens.push( std::move( r ) );
			break;
		}
		case '<':
		{
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = token_ptr( new punc_token( lesseq_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				r = token_ptr( new punc_token( less_tok ) );
				tokens.push( std::move( r ) );
			}
			break;
		}
		case '>':
		{
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = token_ptr( new punc_token( greatereq_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				r = token_ptr( new punc_token( greater_tok ) );
				tokens.push( std::move( r ) );
			}
			break;
		}
		case '=':
		{
			consume();
			if( lookahead() == '=' )
			{
				consume();
				r = token_ptr( new punc_token( equal_tok ) );
				tokens.push( std::move( r ) );
			}
			else
			{
				r = token_ptr( new punc_token( assign_tok ) );
				tokens.push( std::move( r ) );
			}
			break;
		}
		case '#':
		{
			while( lookahead() != '\n' )
			{
				ignore();
			}
		}
		case ' ':
		case '\t':
		case '\n':
			ignore();
			continue;
		default:
		{
			if( std::isalpha( lookahead() ) )
			{				
				do
				{
					consume();
				} while( std::isalpha( lookahead() ) || std::isdigit( lookahead() ) );
				word();

			}
			else if( std::isdigit( lookahead() ) )
			{
				do
				{
					consume();
				} while( !eof() && std::isdigit( lookahead() ) );
				number();
				break;
			}
			else
				throw std::runtime_error( "unknown token encountered\n" );
		}
		}
	}	
}

token_ptr lexer::front()
{
	token_ptr r = nullptr;
	if( !tokens.empty() )
	{
		r = std::move( tokens.front() );
		tokens.pop();
	}

	return r;
}

void lexer::word()
{
	token_ptr r = nullptr;
	auto iter = kw.find( buf );
	
	if( iter != kw.end() )
	{
	
		if( iter->first == "true" ||
			iter->first == "false" )
		{
			r = token_ptr( new bool_token( iter->second ) );
			tokens.push( std::move( r ) );
		}
		// if the buffer is a keyword, but not true/false
		else
		{
			r = token_ptr( new punc_token( iter->second ) );
			tokens.push( std::move( r ) );
		}
	}
	// if the buffer is not a keyword at all, it is a new identifier
	else
	{
		// add new term to symbol table
		auto name = sym.insert( buf );
		r = token_ptr( new id_token( name ) );
		tokens.push( std::move( r ) );
	}
}

void lexer::number()
{
	int n = std::stoi( buf );
	auto r = token_ptr( new int_token( n ) );
	tokens.push( std::move( r ) );
}
