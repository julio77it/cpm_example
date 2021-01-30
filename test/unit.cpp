#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>
#include <operation.h>

namespace op = operations;

TEST_CASE("std::int8_t", "")
{
    std::int8_t a = 5;
    std::int8_t b = 4;
    REQUIRE(op::sum(a,b) == 9);
    REQUIRE(op::sub(a,b) == 1);
    REQUIRE(op::mul(a,b) == 20);
    REQUIRE(op::div(a,b) == 1);
}