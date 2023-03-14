#include "StringLeaf.hpp"

StringLeaf::StringLeaf(std::string value)
    : _value { value }
{}

std::string StringLeaf::print() const
{
    return "\"" + _value + "\"";
}

NodeKind StringLeaf::kind() const
{
    return NodeKind::STRING;
}

std::string StringLeaf::data()
{
    return _value;
}

std::unique_ptr<StringLeaf> StringLeaf::make_ptr(std::string data)
{
    return std::make_unique<StringLeaf>(data);
}