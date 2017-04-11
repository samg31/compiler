#include "token.hpp"

token::token( token_kind tk )
	:tk( tk )
{
}

int_token::int_token( int value )
	:token( int_tok ), value( value )
{
}

std::string int_token::kind()
{
	return std::string( "int" );
}

bool_token::bool_token( int value )
	:token( bool_tok ), value( value )
{
}

std::string bool_token::kind()
{
	return std::string( "bool" );
}

punc_token::punc_token( token_kind tk )
	:token( tk )
{
}

std::string punc_token::kind()
{
	switch( tk )
	{
	case lparen_tok:
		return std::string( "lparen" );
		break;
	case rparen_tok:
		return std::string( "rparen" );
		break;
	case ampersand_tok:
		return std::string( "ampersand" );
		break;
	case bar_tok:
		return std::string( "bar" ); 
		break;
	case caret_tok:
		return std::string( "caret" ); 
		break;
	case exclm_tok:
		return std::string( "exclm" ); 
		break;
	case exclmeq_tok:
		return std::string( "exclmeq" ); 
		break;
	case equal_tok:
		return std::string( "eq" ); 
		break;
	case less_tok:
		return std::string( "less" ); 
		break;
	case greater_tok:
		return std::string( "greater" ); 
		break;
	case lesseq_tok:
		return std::string( "lesseq" ); 
		break;
	case greatereq_tok:
		return std::string( "greatereq" ); 
		break;
	case question_tok:
		return std::string( "question" ); 
		break;
	case colon_tok:
		return std::string( "colon" ); 
		break;
	case plus_tok:
		return std::string( "plus" ); 
		break;
	case minus_tok:
		return std::string( "minus" ); 
		break;
	case asterix_tok:
		return std::string( "asterix" ); 
		break;
	case slash_tok:
		return std::string( "slash" ); 
		break;
	case percent_tok:
		return std::string( "percent" ); 
		break;
	case assign_tok:
		return std::string( "assign" );
		break;
	case semicolon_tok:
		return std::string( "semicolon" );
		break;
	default:
		return std::string( "invalid token" ); 
		break;
	}
}

id_token::id_token( symbol& name )
	:token( id_tok ), name( name )
{
}

std::string id_token::kind()
{
	return std::string( "identifier" );
}
