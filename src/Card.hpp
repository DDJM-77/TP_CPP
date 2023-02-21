#pragma once

#include <string>

enum class CardType
{
    Monster,
    Spell,
    Trap
};

class Card
{
public:
    Card(std::string_view id, const CardType type)
        : _id{id}, _type{type}
    {
    }

    Card(std::string_view id, std::string_view name, const CardType &type, std::string_view desc)
        : _name{name}, _id{id}, _type{type}, _description{desc}
    {
    }

    std::string get_name() const
    {
        return _name;
    }

    std::string get_id() const
    {
        return _id;
    }

    CardType get_type() const
    {
        return _type;
    }

    std::string get_description() const
    {
        return _description;
    }

    void set_name(std::string_view new_name)
    {
        _name = new_name;
    }

    void set_description(std::string_view new_desc)
    {
        _description = new_desc;
    }

    std::string get_symbol() const
    {
        return _symbol;
    }

private:
    std::string _name;
    std::string _id = 0;
    CardType _type;
    std::string _description;

protected:
    std::string _symbol;
};

std::string
to_string(const CardType &type)
{
    if (type == CardType::Monster)
    {
        return "Monster";
    }
    else if (type == CardType::Spell)
    {
        return "Spell";
    }
    else
    {
        return "Trap";
    }
}