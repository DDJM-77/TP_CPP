#pragma once

#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"

#include <variant>
#include <map>
#include <vector>
#include <memory>

class Board
{
    using CardPtr = std::variant<std::unique_ptr<Monster>, std::unique_ptr<Spell>, std::unique_ptr<Trap>>;

public:
    bool put(CardPtr card)
    {
        return std::visit([this](auto &&c)
                          {
                if (c == nullptr)
                {
                    return false;
                }

                if(canPut(c->get_type())){
                    _board_state.push_back(std::move(c));
                    return true;
                }
                return false; },
                          card);
    }

private:
    bool canPut(const CardType &type)
    {
        switch (type)
        {
        case CardType::Monster:
        {
            if (_monster_count < 5)
            {
                _monster_count++;
                _spell_trap_count = 0;
                return true;
            }

            return false;
        }

        case CardType::Spell:
        case CardType::Trap:
        {
            if (_spell_trap_count < 5)
            {
                _monster_count = 0;
                _spell_trap_count++;
                return true;
            }
            return false;
        }

        default:
        {
            return false;
        }
        }
    }

    std::vector<CardPtr> _board_state;
    unsigned int _monster_count = 0;
    unsigned int _spell_trap_count = 0;
};