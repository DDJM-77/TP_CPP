#pragma once

#include "Card.hpp"

enum class SpellType
{
    Continuous,
    Normal,
    Equip,
    QuickPlay,
    Field
};

std::string to_string(const SpellType &spell)
{
    switch (spell)
    {
    case SpellType::Continuous:
        return "Continuous";

    case SpellType::Normal:
        return "Normal";

    case SpellType::Equip:
        return "Equip";

    case SpellType::QuickPlay:
        return "Quick-Play";

    case SpellType::Field:
        return "Field";
    }

    return "";
}

class Spell : public Card
{

public:
    Spell(std::string_view id, std::string_view name, const SpellType type)
        : Card(id, name, CardType::Spell, ""), _type{type}
    {
    }

    SpellType get_spell_type()
    {
        return _type;
    }

private:
    SpellType _type;
};
