#ifndef VALUE_HPP
#define VALUE_HPP

enum value_kind
{
	uninit_val,
	int_val,
	addr_val,
	fn_val
};

union value_data
{
	value_data();
	value_data( int n );
	int n;
};

class value
{
	value_data data;
	value_kind kind;
public:
	value( value_kind, value_data );
	value_data get_data() const;
	value_kind get_kind() const;
};

#endif
