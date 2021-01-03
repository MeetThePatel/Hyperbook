#pragma once

#include <cstdint>
#include <iostream>

#include <fmt/core.h>

enum struct EXECUTION_TYPE : uint8_t { limit = 0, market = 1 };
enum struct ORDER_TYPE : uint8_t { buy = 0, sell = 1 };

struct Order {
  EXECUTION_TYPE	execution_type;
  ORDER_TYPE		order_type;
  uint64_t		order_id;
  uint16_t		equity_id;
  uint16_t		account_id;
  uint16_t		quantity;
  uint16_t		price;	// Price will be kept as integer by multiplying by 100.

  friend std::ostream& operator<< (std::ostream&, const Order&);
  void print();
};
