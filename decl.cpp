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

function_decl::function_decl(
	symbol* name, const type* ret_type, std::vector<decl*>& param )
	:name( name ), return_type( ret_type ), param( param )
{
}

symbol* function_decl::get_name() const
{
	return name;
}

const type* function_decl::get_ret_type() const
{
	return return_type;
}

const std::vector<decl*>& function_decl::get_param() const
{
	return param;
}

program_decl::program_decl( std::vector<stmt*> stmt_seq )
	:statement_seq( stmt_seq )
{
}

const std::vector<stmt*>& program_decl::get_stmt_seq() const
{
	return statement_seq;
}
