#include "Pokemon.h"

#include <iostream>

Pokemon::Pokemon(const std::string &name)
    : _name{name}, _id{_next_id}
{
    _next_id++;
}

Pokemon::Pokemon(const Pokemon &other)
    : _name{other._name}, _id{_next_id}
{
    _next_id++;
}

Pokemon::~Pokemon()
{
    _next_id--;
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

const Trainer *Pokemon::trainer() const
{
    return _trainer;
}

void Pokemon::set_trainer(const Trainer *new_trainer)
{
    _trainer = new_trainer;
}

unsigned int Pokemon::_next_id = 0;
