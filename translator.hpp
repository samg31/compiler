#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <memory>
#include <list>

#include "expr.hpp"
#include "context.hpp"
#include "token.hpp"
#include "decl.hpp"
#include "stmt.hpp"
#include "scope.hpp"

class translator
{
	context& m_cxt;
	std::list<scope>& m_stack;
	const type* next_type;
public:
	translator( context&, std::list<scope>& );
	expr* on_cond( expr&, expr&, expr& );
	expr* on_or( expr&, expr& );
	expr* on_and( expr&, expr& );

	expr* on_equal( expr&, expr& );
	expr* on_inequal( expr&, expr& );
	
	expr* on_less( expr&, expr& );
	expr* on_greater( expr&, expr& );
	expr* on_lesseq( expr&, expr& );
	expr* on_greatereq( expr&, expr& );

	expr* on_add( expr&, expr& );
	expr* on_sub( expr&, expr& );
	expr* on_mul( expr&, expr& );
	expr* on_div( expr&, expr& );
	expr* on_rem( expr&, expr& );

	expr* on_not( expr& );
	expr* on_neg( expr& );
	
	expr* on_bool( bool_token& );
	expr* on_int( int_token& );

	expr* on_ref( id_token& );

	stmt* on_decl_stmt( decl* );
	stmt* on_expr_stmt( expr* );

	decl* on_var_decl( const type*, symbol* );
	decl* on_var_compl( decl*, expr* );

	const type* on_bool_type();
	const type* on_int_type();

	symbol* on_id( token* t );

};

#endif
