#pragma once

class Plush
{
public:
    Plush(unsigned int cost)
        : _cost{cost}
    {
    }

    Plush()
    {
    }

    unsigned int get_cost() const
    {
        return _cost;
    }

    void set_cost(unsigned int value)
    {
        _cost = value;
    }

private:
    unsigned int _cost = 10;
};