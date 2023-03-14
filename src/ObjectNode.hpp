#pragma once

#include "Node.hpp"

#include <map>
#include <memory>
#include <string>

class ObjectNode : public Node
{
public:
    virtual std::string                print() const override;
    virtual NodeKind                   kind() const override;
    static std::unique_ptr<ObjectNode> make_ptr();
    unsigned int                       child_count() const;
    void                               insert(std::string key, NodePtr node);
    virtual unsigned int               height() const override;
    virtual unsigned int               node_count() const override;

private:
    std::map<std::string, NodePtr> _dic;
};