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

class program_decl : public decl
{
	std::vector<stmt*> statement_seq;
public:
	program_decl( std::vector<stmt*> );
};

#endif
