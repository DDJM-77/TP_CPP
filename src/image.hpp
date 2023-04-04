#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename P, size_t W, size_t H>
class Image
{
public:
    Image() {}

    Image(const P& pixel)
        : _pixel { pixel }
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                _pixels[i][j] = _pixel;
            }
        }
    }

    P& operator()(const size_t i, const size_t j) { return _pixels[j][i]; }

    const P& operator()(const size_t i, const size_t j) const { return _pixels[j][i]; }

private:
    P                               _pixel;
    std::array<std::array<P, W>, H> _pixels;
};
