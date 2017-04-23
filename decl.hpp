#ifndef DECL_HPP
#define DECL_HPP

#include "symbol.hpp"
#include "type.hpp"
#include "expr.hpp"

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

#endif
