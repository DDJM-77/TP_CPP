#pragma once

#include "../lib/Unit.hpp"

#include <algorithm>
#include <vector>

class Kitchen
{
public:
    Unit& register_unit(Unit new_unit);
    Unit* find_unit(const std::string& str);

private:
    std::vector<std::reference_wrapper<Unit>> _all_units;
};
