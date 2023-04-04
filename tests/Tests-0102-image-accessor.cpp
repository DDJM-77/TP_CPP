#include "../src/image.hpp"
#include "../src/pixels.hpp"

#include <catch2/catch_test_macros.hpp>
#include <complex>
#include <iostream>
#include <type_traits>

TEST_CASE("Image pixel access with image(i,j)")
{
    Image<int, 4, 4> img(0);
    img(1, 2) = 2;
    img(2, 1) = 5;

    REQUIRE(img(1, 2) == 2);
    REQUIRE(img(2, 1) == 5);
}

TEST_CASE("Same thing but const")
{
    const Image<int, 4, 4> img(3);

    REQUIRE(img(1, 2) == 3);
    REQUIRE(img(2, 1) == 3);
}
