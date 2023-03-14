#pragma once

#include "Node.hpp"

class Leaf : public Node
{
protected:
    Leaf() {}

public:
    virtual unsigned int height() const override;
    virtual unsigned int node_count() const override;
};