#pragma once

#include "Pokemon.h"
#include <vector>
#include <memory>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    std::vector<PokemonPtr> &pokemons();
    bool empty() const;
    void transfer(PokemonPtr pokemon);
    PokemonPtr get_pokemon(Trainer &trainer, std::string_view pokemon_name);

private:
    std::vector<PokemonPtr> _pokemons;
};