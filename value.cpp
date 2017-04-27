#include "value.hpp"

value::value( value_kind kind, value_data data )
	:kind( kind ), data( data )
{
}

value_data value::get_data() const
{
	return data;
}

value_kind value::get_kind() const
{
	return kind;
}

value_data::value_data()
{
}

value_data::value_data( int n )
	:n( n )
{
}
