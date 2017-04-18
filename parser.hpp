#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>
#include <memory>

#include "lexer.hpp"
#include "context.hpp"
#include "token.hpp"
#include "expr.hpp"
#include "type.hpp"
#include "translator.hpp"

using expr_ptr = std::unique_ptr<expr>;

class parser
{
	lexer& m_lexer;
	context& m_cxt;
	std::deque<token_ptr> tokens;
	translator sema;
public:	
	parser( lexer& l, context& cxt );

	token_kind lookahead();
	token_ptr consume();
	token_ptr match( token_kind tk );
	token_ptr match_if( token_kind tk );
	
	expr_ptr expression();
	expr_ptr additive_expression();
	expr_ptr multiplicative_expression();
	expr_ptr conditional_expression();
	expr_ptr logical_or_expression();
	expr_ptr logical_and_expression();
	expr_ptr equality_expression();
	expr_ptr ordering_expression();	
	expr_ptr unary_expression();	
	expr_ptr primary_expression();
};


#endif
