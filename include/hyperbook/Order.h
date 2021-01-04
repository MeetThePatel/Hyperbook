/** \file Order.h
 *  \brief This file is for things related to orders.
 */

#pragma once

#include <cstdint>
#include <iostream>

#include <fmt/core.h>

/** \enum ORDER_TYPE
 *  \brief An enum for the execution type of the order.
 *
 *  Signifies whether the order is a limit order or a market order.
 */

enum struct ORDER_TYPE : uint8_t {
  limit	 = 0,	//!< Limit Order.
  market = 1	//!< Market Order.
};

/** \enum ORDER_SIDE
 *  \brief An enum for the side of the order.
 *
 *  Signifies whether the order is a buy order or a sell order.
 */

enum struct ORDER_SIDE : uint8_t {
  buy  = 0,	//!< Buy Order.
  sell = 1	//!< Sell Order.
};

/** \struct Order
 *  \brief This struct represents an order being sent to the order matcher.
 */

struct Order {
  ORDER_TYPE	order_type;	//!< Signifies whether the order is a limit order or a market order.
  ORDER_SIDE	order_side;	//!< Signifies whether the order is a buy order or a sell order.
  uint64_t	order_id;	//!< Unique ID number of the order.
  uint16_t	equity_id;	//!< ID number of the target equity.
  uint16_t	account_id;	//!< ID number of the account placing the order.
  uint16_t	quantity;	//!< Quantity of shares being ordered.
  uint16_t	price;		//!< Target price of shares (0 if market order).

  /** \fn print
   *  \brief Print out the Order, formatted with fmt.
   */
  void print();
};
