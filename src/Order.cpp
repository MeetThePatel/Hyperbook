#include <hyperbook/Order.h>
#include <iomanip>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/locale.h>

std::ostream &operator<<(std::ostream &os, const Order &order) {
  os << fmt::format(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
		   "{:>{}} ", order.order_id, 10)
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   ": Account ")
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
		   " #{} ", order.account_id)
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   " placed a ")
     << ((order.execution_type == EXECUTION_TYPE::limit)
	? fmt::format(fg(fmt::color::light_coral) | bg(fmt::color::black) | fmt::emphasis::bold,
		      "{:^{}}", "LIMIT", 8)
	: fmt::format(fg(fmt::color::light_blue) | bg(fmt::color::black) | fmt::emphasis::bold,
		      "{:^{}}", "MARKET", 8))
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   " order for ")
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   " {} ", order.quantity)
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   " shares of ")
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
		   " {} ", order.equity_id)
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   " at ")
     << fmt::format(fg(fmt::color::light_green) | bg(fmt::color::black) | fmt::emphasis::bold,
                    " $ {:>8.2f} ", (double)order.price / 100.0)
     << fmt::format(fg(fmt::color::white) | bg(fmt::color::black),
		   ".");
  return os;
}

// This is much faster than std::cout << ... .
void Order::print() {
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
	     "{:>{}} ", this->order_id, 10);
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     ": Account ");
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
	     " #{:>{}} ", this->account_id, 5);
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     " placed a ");
  ((this->execution_type == EXECUTION_TYPE::limit)
   ? fmt::print(fg(fmt::color::light_coral) | bg(fmt::color::black) | fmt::emphasis::bold,
		"{:^{}}", "LIMIT", 8)
   : fmt::print(fg(fmt::color::light_blue) | bg(fmt::color::black) | fmt::emphasis::bold,
		"{:^{}}", "MARKET", 8));
  ((this->order_type == ORDER_TYPE::buy)
   ? fmt::print(fg(fmt::color::black) | bg(fmt::color::light_green) | fmt::emphasis::bold,
		"{:^{}}", "BUY", 6)
   : fmt::print(fg(fmt::color::black) | bg(fmt::color::light_coral) | fmt::emphasis::bold,
		"{:^{}}", "SELL", 6));
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     " order for ");
  std::locale x("en_US.UTF-8");
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     fmt::format(x, " {:>7L} ", this->quantity));
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     " shares of ");
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black) | fmt::emphasis::bold,
	     " {:>{}} ", this->equity_id, 5);
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     " at ");
  fmt::print(fg(fmt::color::light_green) | bg(fmt::color::black) | fmt::emphasis::bold,
	     " $ {:>7.2f} ", (double)this->price / 100.0);
  fmt::print(fg(fmt::color::white) | bg(fmt::color::black),
	     ".");
  std::cout << '\n';
}
