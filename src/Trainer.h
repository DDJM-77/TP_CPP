#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"

#include <array>
// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc);

    const std::string name() const;
    const std::array<Pokeball, 6> &pokeballs() const;
    void capture(PokemonPtr pokemon);
    void store_in_pc(unsigned int index);
    void fetch_from_pc(std::string_view pokemon_name);
    const Pokedex &pokedex();

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _pokeballs;
    Pokedex _pokedex;
};
