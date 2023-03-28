#include "Kitchen.hpp"

#include <memory>

Unit& Kitchen::register_unit(Unit new_unit)
{
    _all_units.emplace_back(new_unit);
    return _all_units.back();
}

Unit* Kitchen::find_unit(const std::string& str)
{
    auto it =
        std::find_if(_all_units.begin(), _all_units.end(), [str](Unit str_1) { return str_1.name == str; });
    if (it != _all_units.end())
    {
        return &(it->get());
    }

    return nullptr;
}