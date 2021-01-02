#ifndef LIMITORDERBOOK_H
#define LIMITORDERBOOK_H

#include <list>
#include <queue>
#include <cstdint>

#include <hyperbook/Order.h>

enum struct LOB_SIDE : uint8_t { bid = 0, ask = 1 };

struct LimitOrderBookLevel {
  std::queue<Order>	level;
  uint64_t		level_volume;

  int insert(Order);
};

struct LimitOrderBook {
  LOB_SIDE				lob_side;
  std::list<LimitOrderBookLevel>	book;
  uint64_t				book_volume;

  int insert(Order);
};

struct OrderBook {
  LimitOrderBook	bid_book;
  LimitOrderBook	ask_book;
  uint64_t		total_volume;

  OrderBook();
  ~OrderBook();

  int insert(Order);
};

#endif
