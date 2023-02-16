#include "Trainer.h"

#include <iostream>
Trainer::Trainer(const std::string &name, PC &pc)
    : _name{name}, _pc{pc}
{
}

const std::string Trainer::name() const
{
    return _name;
}

const std::array<Pokeball, 6> &Trainer::pokeballs() const
{
    return _pokeballs;
}

void Trainer::capture(PokemonPtr pokemon)
{
    pokemon->set_trainer(this);
    _pokedex.add(*pokemon);

    for (unsigned int index = 0; index < _pokeballs.size(); index++)
    {
        if (_pokeballs[index].empty())
        {
            _pokeballs[index].store(std::move(pokemon));
            return;
        }
    }

    _pc.transfer(std::move(pokemon));
}

void Trainer::store_in_pc(unsigned int index)
{
    _pc.transfer(_pokeballs[index].withdraw_pokemon());
    // if (index < _pokeballs.size() && !_pokeballs[index].empty())
    // {
    //     auto pokemon = _pokeballs[index].pokemon();
    //     _pokeballs[index].withdraw_pokemon();
    //     _pc.transfer(std::make_unique<Pokemon>(pokemon));
    // }
}

void Trainer::fetch_from_pc(std::string_view pokemon_name)
{
    for (unsigned int index = 0; index < _pokeballs.size(); index++)
    {
        if (_pokeballs[index].empty())
        {
            auto pokemon = _pc.get_pokemon(*this, pokemon_name);
            if (pokemon != nullptr)
            {
                _pokeballs[index].store(std::move(pokemon));
                return;
            }
        }
    }
}

const Pokedex &Trainer::pokedex()
{
    return _pokedex;
}