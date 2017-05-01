#include "token.hpp"
#include <cassert>

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

std::string int_token::print_value()
{
	return std::to_string( get_value() );
}

int int_token::get_value() const
{
	return value;
}

bool_token::bool_token( token_kind tk )
	:token( tk )
{
	assert( tk == true_kw_tok || tk == false_kw_tok );

	value = ( tk == true_kw_tok ) ? true : false;
}

std::string bool_token::kind()
{
	if( tk == true_kw_tok )
		return std::string( "true_kw" );

	if( tk == false_kw_tok )
		return std::string( "false_kw" );
}

std::string bool_token::print_value()
{
	return std::to_string( value );
}

int bool_token::get_value() const
{
	return value;
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
	case var_kw_tok:
		return std::string( "var_kw" );
		break;
	case int_kw_tok:
		return std::string( "int_kw" );
		break;
	case bool_kw_tok:
		return std::string( "bool_kw" );
		break;
	default:
		return std::string( "invalid token" ); 
		break;
	}
}

std::string punc_token::print_value()
{
	return std::string( "no value\n" );
}

id_token::id_token( symbol* name )
	:token( id_tok ), name( name )
{
}

symbol* id_token::get_name() const
{
	return name;
}

std::string id_token::kind()
{
	return std::string( "identifier" );
}

std::string id_token::print_value()
{
	return std::string( "no value\n" );
}

keyword_table::keyword_table()
{
	insert( { "true", true_kw_tok } );
	insert( { "false", false_kw_tok } );
	insert( { "var", var_kw_tok } );
	insert( { "int", int_kw_tok } );
	insert( { "bool", bool_kw_tok } );
	insert( { "print", print_kw_tok } );
	insert( { "while", while_kw_tok } );
	insert( { "if", while_kw_tok } );
}
