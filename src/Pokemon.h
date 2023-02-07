#pragma once

#include <string>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string &name);
    Pokemon(const Pokemon &pokemon);
    ~Pokemon();

    const std::string &name() const;
    unsigned int id() const;
    Pokemon &operator=(const Pokemon &other);

private:
    std::string _name;
    unsigned int _id = 0;
    static unsigned int _next_id;
};
