#include "scope.hpp"

bool scope::insert( symbol* s, decl* d )
{
	auto it = m_table.insert( {s, d} );

	// return true if the insertion was successful
	return it.second;
}

decl* scope::find( symbol* s )
{
	auto it = m_table.find( s );

	return ( it != m_table.end() ) ? it->second : nullptr;
}
