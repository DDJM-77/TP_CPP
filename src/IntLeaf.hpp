#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value);

    virtual NodeKind                kind() const override;
    virtual std::string             print() const override;
    int                             data();
    static std::unique_ptr<IntLeaf> make_ptr(int data);

private:
    int _value = 0;
};