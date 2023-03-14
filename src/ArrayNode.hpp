#pragma once

#include "Node.hpp"

#include <vector>

class ArrayNode : public Node
{

public:
    virtual std::string               print() const override;
    virtual NodeKind                  kind() const override;
    static std::unique_ptr<ArrayNode> make_ptr();
    unsigned int                      child_count() const;
    void                              push_back(NodePtr node);
    virtual unsigned int              height() const override;
    virtual unsigned int              node_count() const override;

private:
    std::vector<NodePtr> _array;
};