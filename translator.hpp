#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <memory>

#include "expr.hpp"
#include "context.hpp"
#include "token.hpp"

using expr_ptr = std::unique_ptr<expr>;

class translator
{
	context& m_cxt;
public:
	translator( context& cxt );
	expr_ptr on_cond( expr&, expr&, expr& );
	expr_ptr on_or( expr&, expr& );
	expr_ptr on_and( expr&, expr& );

	expr_ptr on_equal( expr&, expr& );
	expr_ptr on_inequal( expr&, expr& );
	
	expr_ptr on_less( expr&, expr& );
	expr_ptr on_greater( expr&, expr& );
	expr_ptr on_lesseq( expr&, expr& );
	expr_ptr on_greatereq( expr&, expr& );

	expr_ptr on_add( expr&, expr& );
	expr_ptr on_sub( expr&, expr& );
	expr_ptr on_mul( expr&, expr& );
	expr_ptr on_div( expr&, expr& );
	expr_ptr on_rem( expr&, expr& );

	expr_ptr on_not( expr& );
	expr_ptr on_neg( expr& );
	
	expr_ptr on_bool( bool_token& );
	expr_ptr on_int( int_token& );

};

#endif
