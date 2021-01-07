/** \file OrderBook.h
 *  \brief This file is for things related to the order book.
 */

#pragma once

#include <queue>
#include <list>
#include <unordered_map>
#include <cstdint>

#include <hyperbook/Order.h>

/** \struct OrderBookLevel
 *  \brief This struct represents a price level in the OrderBook.
 */

struct OrderBookLevel {
  USD			price_level;	//!< Price that this OrderBookLevel is at.
  ORDER_SIDE		side;		//!< Signifies whether this OrderBookLevel is a bid or ask.
  std::queue<Order>	orders;		//!< Queue of Orders at this price level.
  uint16_t		level_volume;	//!< Volume of Orders at this price level.

  /** \brief This is a default constructor for an OrderBookLevel.
   *
   *  The reason it is not deleted is to ensure that the constructor for
   *  OrderBook can create default values for each price level.
   *  @see OrderBook(USD previous_close, float price_band_percentage).
   */
  
  OrderBookLevel () = default;

  /** \brief This is the primary constructor for an OrderBookLevel.
   *  \param price_level of the OrderBookLevel.
   *  \param side of the order book that this price level is on.
   */
  
  OrderBookLevel (USD price_level, ORDER_SIDE side);
};

/** \struct OrderBook
 *  \brief This class represents the order book for a particular security.
 */

struct OrderBook {
  std::vector<OrderBookLevel>	data;		//!< Vector of OrderBookLevels.
  uint64_t			bid_volume;	//!< Total volume of bid orders.
  uint64_t			ask_volume;	//!< Total volume of ask orders.

  std::vector<OrderBookLevel>::iterator last;		//!< Iterator to the OrderBookLevel of the last sale.
  std::vector<OrderBookLevel>::iterator lowest_ask;	//!< Iterator to the OrderBookLevel of the lowest ask Order.
  std::vector<OrderBookLevel>::iterator highest_bid;	//!< Iterator to the OrderBookLevel of the highest bid Order.

  /** \brief This is the primary constructor for an Order Book.
   *  \param previous_close of the equity.
   *  \param price_band_percentage is the maximum deviation (in percentage)
   *  allowed by LimitUpLimitDown.
   */
 
  OrderBook (USD previous_close, float price_band_percentage);

  /** \brief Returns the Limit Down price level. */
  constexpr USD get_limit_down () const {return this->data.front().price_level;};

  /** \brief Returns the Limit Up price level. */
  constexpr USD get_limit_up () const {return this->data.back().price_level;};
};

/** \struct OrderBooks
 *  \brief This struct represents all of the OrderBooks being handled by the Hyperbook.
 */

struct OrderBooks {
  std::unordered_map<uint16_t, std::unique_ptr<OrderBook>> order_books;

  std::unique_ptr<Order>	insert	(Order);
  uint8_t			cancel	(std::unique_ptr<Order>);
  void				publish ();
};
