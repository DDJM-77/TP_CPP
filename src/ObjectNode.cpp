#include "ObjectNode.hpp"

NodeKind ObjectNode::kind() const
{
    return NodeKind::OBJECT;
}

std::string ObjectNode::print() const
{
    std::string result = "{";
    std::string sep    = "";
    for (auto it = _dic.begin(), end = _dic.end(); it != end; it++)
    {
        result += sep + "\"" + it->first + "\":" + it->second->print();
        sep = ",";
    }
    return result + "}";
}

std::unique_ptr<ObjectNode> ObjectNode::make_ptr()
{
    return std::make_unique<ObjectNode>();
}

unsigned int ObjectNode::child_count() const
{
    return _dic.size();
}

void ObjectNode::insert(std::string key, NodePtr node)
{
    _dic[key] = std::move(node);
}

unsigned int ObjectNode::height() const
{
    return 0;
}
unsigned int ObjectNode::node_count() const
{
    return 0;
}