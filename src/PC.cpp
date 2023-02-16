#include "PC.h"

std::vector<PokemonPtr> &PC::pokemons()
{
    return _pokemons;
}

bool PC::empty() const
{
    return _pokemons.size() == 0;
}

void PC::transfer(PokemonPtr pokemon)
{
    if (pokemon != nullptr)
    {
        _pokemons.emplace_back(std::move(pokemon));
    }
}

PokemonPtr PC::get_pokemon(Trainer &trainer, std::string_view pokemon_name)
{
    for (unsigned long i = 0; i < _pokemons.size(); i++)
    {

        if (_pokemons[i]->name() == pokemon_name && _pokemons[i]->trainer() == &trainer)
        {
            auto result = std::move(_pokemons[i]);
            _pokemons.erase(_pokemons.begin() + i);
            return result;
        }
    }
    return nullptr;
}