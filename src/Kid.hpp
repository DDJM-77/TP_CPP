#pragma once

#include <string>
#include <ostream>
#include "PlushStore.hpp"
#include "Plush.hpp"

class Kid
{
public:
    Kid(std::string name, unsigned int money)
        : _name{name}, _money{money}
    {
    }

    const std::string &get_name() const
    {
        return _name;
    }

    unsigned int get_money() const
    {
        return _money;
    }

    void buy_plush(PlushStore &plush_store)
    {
        auto plush_bought = plush_store.buy(_money);
        if (plush_bought != std::nullopt)
        {
            _money -= plush_bought.value().get_cost();
        }
    }

private:
    std::string _name;
    unsigned int _money = 0;
};

std::ostream &operator<<(std::ostream &stream, const Kid &kid)
{
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}