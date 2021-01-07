#pragma once

#include <queue>
#include <list>
#include <unordered_map>
#include <cstdint>

#include <hyperbook/Order.h>

struct OrderBookLevel {
  USD price_level;
  ORDER_SIDE		side;
  std::queue<Order>	orders;
  uint16_t		level_volume;

  OrderBookLevel () = default;
  OrderBookLevel (USD price_level, ORDER_SIDE side);
};

struct OrderBook {
  std::vector<OrderBookLevel>	data;
  uint64_t			bid_volume;
  uint64_t			ask_volume;

  std::vector<OrderBookLevel>::iterator last;
  std::vector<OrderBookLevel>::iterator lowest_ask;
  std::vector<OrderBookLevel>::iterator highest_bid;

  OrderBook (USD previous_close, float price_band_percentage);

  USD get_limit_down () const;
  USD get_limit_up () const;
};

struct OrderBooks {
  std::unordered_map<uint16_t, std::unique_ptr<OrderBook>> order_books;

  std::unique_ptr<Order>	insert	(Order);
  uint8_t			cancel	(std::unique_ptr<Order>);
  void				publish ();
};
