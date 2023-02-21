#pragma once

#include "Card.hpp"
#include <string>

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

std::string to_symbol(const Attribute &attr)
{
    switch (attr)
    {
    case Attribute::Dark:
        return u8"闇";

    case Attribute::Divine:
        return u8"神";

    case Attribute::Earth:
        return u8"地";

    case Attribute::Fire:
        return u8"炎";

    case Attribute::Light:
        return u8"光";

    case Attribute::Water:
        return u8"水";

    case Attribute::Wind:
        return u8"風";
    }

    return "";
}

class Monster : public Card
{
public:
    Monster(std::string_view id, std::string_view name, const Attribute &attribute, std::string_view desc, unsigned int atk, unsigned int def)
        : Card(id, name, CardType::Monster, desc), _attribute{attribute}, _atk{atk}, _def{def}, _initial_desc{desc}
    {
        _symbol = to_symbol(_attribute);
    }

    Attribute get_attribute() const
    {
        return _attribute;
    }

    unsigned int get_atk() const
    {
        return _atk;
    };

    unsigned int get_def() const
    {
        return _def;
    };

    std::string get_description() const
    {
        return "[" + _initial_desc + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
    }

private:
    Attribute _attribute;
    unsigned int _atk = 0u;
    unsigned int _def = 0u;
    std::string _initial_desc;
};