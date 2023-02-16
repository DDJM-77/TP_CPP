#pragma once

#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string &name);
    Pokemon(const Pokemon &other);
    ~Pokemon();

    const std::string &name() const;
    unsigned int id() const;
    Pokemon &operator=(const Pokemon &other);
    const Trainer *trainer() const;
    void set_trainer(const Trainer *new_trainer);

private:
    std::string _name;
    unsigned int _id = 0;
    static unsigned int _next_id;
    const Trainer *_trainer = nullptr;
};

using PokemonPtr = std::unique_ptr<Pokemon>;