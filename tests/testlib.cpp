#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <hyperbook/Order.h>

TEST_CASE("Ensure correct size of Order", "[Order]") {
  Order x {EXECUTION_TYPE::limit, ORDER_TYPE::buy, 0, 634, 100, 10000, 9430};
  REQUIRE(sizeof(x) == 24);
}
