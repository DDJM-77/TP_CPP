#pragma once

#include <string>
#include <optional>
#include "Plush.hpp"
#include <vector>

class PlushStore
{
public:
    PlushStore(std::string store_name)
        : _store_name{store_name}
    {
    }

    const std::string &get_name() const
    {
        return _store_name;
    }

    unsigned int get_wealth_amount() const
    {
        return _wealth;
    }

    unsigned int get_stock_size() const
    {
        return _stock;
    }

    void loan(unsigned int wealth)
    {
        _wealth += wealth;
        _debt = _wealth + (10 * _wealth) / 100;
    }

    unsigned int get_debt_amount()
    {
        return _debt;
    }

    unsigned int make_plush(unsigned int plush_production)
    {
        if (_wealth > 0)
        {
            _stock++;
            _exp++;
            _plushes.emplace_back(plush_production + _exp);
        }
        if (plush_production > _wealth)
        {
            _wealth = 0;
        }
        else
        {
            _wealth = _wealth - plush_production;
        }
        return plush_production + _exp;
    }

    unsigned int get_experience()
    {
        return _exp;
    }

    std::optional<Plush> buy(unsigned int money)
    {
        unsigned int index = 0;
        unsigned int i = 0;
        bool default_plush = true;
        Plush min_plush;
        for (Plush plush : _plushes)
        {
            auto val = plush.get_cost();
            if ((default_plush == true && val <= money) || (min_plush.get_cost() <= money && min_plush.get_cost() > val))
            {
                min_plush = plush;
                default_plush = false;
                index = i;
            }
            i++;
        }

        if (!default_plush)
        {
            remove_plush(min_plush.get_cost(), index);
            return std::optional<Plush>{min_plush};
        }
        return std::nullopt;
    }

private:
    void remove_plush(unsigned int price, unsigned int index)
    {
        if (_stock > 0)
        {
            _stock--;
        }
        _wealth += price;
        _plushes.erase(_plushes.begin() + index, _plushes.begin() + index + 1);
    }

    std::string _store_name;
    unsigned int _wealth = 0;
    unsigned int _stock = 0;
    unsigned int _debt = 0;
    unsigned int _exp = 0;
    std::vector<unsigned int> _plushes;
};