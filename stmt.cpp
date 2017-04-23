#include "stmt.hpp"

expr_stmt::expr_stmt( expr* expression )
	:expression( expression )
{
}

decl_stmt::decl_stmt( decl* entity )
	:entity( entity )
{
}
