#ifndef UTIL_HPP
#define UTIL_HPP

#include <list>
#include "scope.hpp"
#include "symbol.hpp"
#include "decl.hpp"

using stack = std::list<scope>;

inline decl* scope_lookup( stack& s, symbol* name )
{
	// look up the name in every individual scope,
	// starting from the smallest and ending at the global scope
	for( auto& i : s )
	{
		auto result = i.find( name );

		// result will be non-null if it was found
		if( result )
			return result;
	}
	// return nullptr if the name is in no scope
	return nullptr;
}

#endif
