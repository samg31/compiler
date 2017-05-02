#ifndef DECL_HPP
#define DECL_HPP

#include <vector>

#include "symbol.hpp"
#include "type.hpp"
#include "expr.hpp"

class stmt;

class decl
{
public:
	virtual ~decl() = default;
};

class var_decl : public decl
{
public:
	symbol* m_name;
	const type* m_type;
	expr* m_init;
	bool m_initialized;
	
public:
	var_decl( symbol*, const type* );
	void set_init( expr* );
};

class function_decl : public decl
{
	symbol* name;
	const type* return_type;
	std::vector<decl*> param;
public:
	// functions take the form f( t_0 p_0, ..., t_n p_n ) -> t
	// the point of declaration is immediately after the return type,
	// thus the name, return type, and parameters must be
	// defined on construction.
	function_decl( symbol*, const type*, std::vector<decl*>& );

	symbol* get_name() const;
	const type* get_ret_type() const;
	const std::vector<decl*>& get_param() const;
	
	stmt* body;
	decl* ret;
};

class param_decl : public decl
{
	symbol* name;
	const type* ty;
public:
	param_decl( symbol*, const type* );
	param_decl( symbol*, const type*, expr* );

	symbol* get_name() const;
	const type* get_type() const;

	expr* init;
};

class program_decl : public decl
{
	std::vector<stmt*> statement_seq;
public:
	program_decl( std::vector<stmt*> );
	const std::vector<stmt*>& get_stmt_seq() const;
};

#endif
