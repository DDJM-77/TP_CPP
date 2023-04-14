#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>> l2)
{
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() && it2 != l2.end())
    {
        concatenate(*it1, std::move(*it2));
        it1++;
        it2++;
    }
}