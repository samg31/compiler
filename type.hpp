#ifndef TYPE_HPP
#define TYPE_HPP

class type
{
public:
	virtual ~type() = default;
};

class bool_type : public type
{
};

class int_type : public type
{
};

#endif
