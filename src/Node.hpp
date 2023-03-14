#pragma once

#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class Node;

using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
protected:
    Node();

public:
    virtual std::string print() const = 0;
    virtual NodeKind    kind() const  = 0;
    virtual ~Node();
    virtual unsigned int height() const     = 0;
    virtual unsigned int node_count() const = 0;
};
