#pragma once

#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const;
    void store(PokemonPtr pokemon);
    const Pokemon &pokemon() const;
    void withdraw_pokemon();

private:
    bool _full = false;
    PokemonPtr _pokemon_stored = nullptr;
};
