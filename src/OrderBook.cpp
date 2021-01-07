#include "hyperbook/Order.h"
#include <hyperbook/OrderBook.h>

OrderBookLevel::OrderBookLevel (USD price_level, ORDER_SIDE side) {
  this->price_level = price_level;
  this->side = side;
  this->level_volume = 0;
}

OrderBook::OrderBook(USD previous_close, float price_band_percentage) {
  uint16_t diff = previous_close * price_band_percentage;
  this->data = std::vector<OrderBookLevel>(2 * diff + 1);
  for (int i = 0; i < diff + 1; ++i) {
    this->data[i].price_level = previous_close - diff + i;
    this->data[i].side = ORDER_SIDE::buy;
  }
  for (int i = diff + 1; i < 2 * diff + 1; ++i) {
    this->data[i].price_level = previous_close - diff + i;
    this->data[i].side = ORDER_SIDE::sell;
  }
  this->last  = this->data.begin() + diff;
  this->highest_bid = this->data.begin() + diff;
  this->lowest_ask = this->data.begin() + diff + 1;
}
