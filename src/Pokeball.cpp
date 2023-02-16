#include "Pokeball.h"
#include <iostream>

bool Pokeball::empty() const
{
    return !_full;
}

void Pokeball::store(PokemonPtr pokemon)
{
    _pokemon_stored = std::move(pokemon);
    _full = true;
}

const Pokemon &Pokeball::pokemon() const
{
    return *_pokemon_stored;
}

void Pokeball::withdraw_pokemon()
{
    _full = false;
    _pokemon_stored = nullptr;
}
