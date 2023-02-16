#include "Pokedex.h"

void Pokedex::add(const Pokemon &pokemon)
{
    _pokedex[pokemon.name()].emplace_back(&pokemon);
}

const std::vector<const Pokemon *> &Pokedex::find(const std::string &poke_name) const
{
    const auto it = _pokedex.find(poke_name);
    return it == _pokedex.end() ? empty_list : it->second;
}