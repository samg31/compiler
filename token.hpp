#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <unordered_map>
#include "symbol.hpp"

enum token_kind
{
	eof_tok,
	lparen_tok,
	rparen_tok,
	ampersand_tok,
	bar_tok,
	caret_tok,
	exclm_tok,
	exclmeq_tok,
	int_tok,
	bool_tok,
	equal_tok,
	less_tok,
	greater_tok,
	lesseq_tok,
	greatereq_tok,
	question_tok,
	colon_tok,
	plus_tok,
	minus_tok,
	asterix_tok,
	slash_tok,
	percent_tok,
	assign_tok,
	semicolon_tok,
	id_tok,
	true_kw_tok,
	false_kw_tok,
	var_kw_tok,
	int_kw_tok,
	bool_kw_tok
};

class keyword_table : public std::unordered_map<std::string, token_kind>
{
public:
	keyword_table()
	{
		insert( { "true", true_kw_tok } );
		insert( { "false", false_kw_tok } );
		insert( { "var", var_kw_tok } );
		insert( { "int", int_kw_tok } );
		insert( { "bool", bool_kw_tok } );
	}	
};

class token
{
protected:
	token_kind tk;
public:
	token( token_kind tk );
	virtual std::string kind() = 0;

	virtual ~token() = default;
};

class int_token : public token
{
	int value;
public:
	int_token( int );
	int get_value() const;
	std::string kind() override;
};

class bool_token : public token
{
	int value;
public:
	bool_token( int );
	int get_value() const;
	std::string kind() override;
};

class punc_token : public token
{
public:
	punc_token( token_kind tk );
	std::string kind() override;
};

class id_token : public token
{
	symbol& name;
public:
	id_token( symbol& name );
	std::string kind() override;
};

#endif
