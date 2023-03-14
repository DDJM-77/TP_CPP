#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(std::string value);

    virtual std::string                print() const override;
    virtual NodeKind                   kind() const override;
    std::string                        data();
    static std::unique_ptr<StringLeaf> make_ptr(std::string data);

private:
    std::string _value;
};