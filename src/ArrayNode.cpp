#include "ArrayNode.hpp"

NodeKind ArrayNode::kind() const
{
    return NodeKind::ARRAY;
}

std::string ArrayNode::print() const
{
    std::string result = "[";
    size_t      limit  = _array.size();
    std::string sep;
    for (size_t i = 0; i < limit; i++)
    {
        result += sep + _array[i]->print();
        sep = ",";
    }
    result += "]";
    return result;
}

std::unique_ptr<ArrayNode> ArrayNode::make_ptr()
{
    return std::make_unique<ArrayNode>();
}

unsigned int ArrayNode::child_count() const
{
    return _array.size();
}

void ArrayNode::push_back(NodePtr node)
{
    _array.push_back(std::move(node));
}

unsigned int ArrayNode::height() const
{
    return 0;
}
unsigned int ArrayNode::node_count() const
{
    return 0;
}