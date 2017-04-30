#include "decl.hpp"

var_decl::var_decl( symbol* name, const type* ty )
	:m_name( name ), m_type( ty ), m_initialized( false )
{
}

void var_decl::set_init( expr* e )
{
	if( m_initialized )
		throw std::runtime_error(
			"variable has already been initialized\n" );
	else
		m_init = e;
}

program_decl::program_decl( std::vector<stmt*> stmt_seq )
	:statement_seq( stmt_seq )
{
}
