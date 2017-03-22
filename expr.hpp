#ifndef EXPR_HPP
#define EXPR_HPP

class expr;
class bool_expr;

class expr
{
public:
	struct visitor;
	virtual void accept( visitor& v ) = 0;
	virtual ~expr() = default;
};

struct expr::visitor
{
	virtual void visit( bool_expr& ) = 0;
};

class bool_expr : public expr
{
	int value;
public:
	bool_expr( int value );
	void accept( visitor& v );
	int get_value() const;
};

#endif
