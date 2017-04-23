#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <unordered_map>

#include "symbol.hpp"
#include "decl.hpp"

class scope
{
	std::unordered_map<symbol*, decl*> m_table;
	
public:
	bool insert( symbol*, decl* );

	decl* find( symbol* );
};

#endif
