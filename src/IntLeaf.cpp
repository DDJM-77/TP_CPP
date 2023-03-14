#include "IntLeaf.hpp"

IntLeaf::IntLeaf(int value)
    : Leaf {}
    , _value { value }
{}

std::string IntLeaf::print() const
{
    return std::to_string(_value);
}

int IntLeaf::data()
{
    return _value;
}

NodeKind IntLeaf::kind() const
{
    return NodeKind::INT;
}

std::unique_ptr<IntLeaf> IntLeaf::make_ptr(int data)
{
    return std::make_unique<IntLeaf>(data);
}
