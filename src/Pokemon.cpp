#include "Pokemon.h"

Pokemon::Pokemon(const std::string &name)
    : _name{name}, _id{_next_id}
{
    _next_id++;
}

Pokemon::~Pokemon()
{
    _next_id--;
}

Pokemon::Pokemon(const Pokemon &pokemon)
    : Pokemon(pokemon._name)
{
}

const std::string &Pokemon::name() const
{
    return _name;
}

unsigned int Pokemon::id() const
{
    return _id;
}

Pokemon &Pokemon::operator=(const Pokemon &other)
{
    if (this != &other)
    {
        _name = other._name;
    }

    return *this;
}

unsigned int Pokemon::_next_id = 0;
