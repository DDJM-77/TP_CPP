#pragma once

#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

std::string to_string(const TrapType &trap)
{
    switch (trap)
    {
    case TrapType::Normal:
        return "Normal";

    case TrapType::Continuous:
        return "Continuous";

    case TrapType::Counter:
        return "Counter";
    }

    return "";
}

class Trap : public Card
{
public:
    Trap(std::string_view id, std::string_view name, const TrapType type)
        : Card(id, name, CardType::Trap, ""), _type{type}
    {
        _symbol = u8"罠";
    }

    TrapType get_trap_type()
    {
        return _type;
    }

private:
    TrapType _type;
};
