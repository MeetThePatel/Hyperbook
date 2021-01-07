#include <chrono>

#include <hyperbook/hyperbook.h>
#include <hyperbook/Order.h>
#include <hyperbook/OrderBook.h>

int main() {

  auto start = std::chrono::high_resolution_clock::now();

  OrderBook x{10000, 0.05};
  Order y {ORDER_TYPE::limit, ORDER_SIDE::buy, 0, 634, 100, 10000, 9430};

  std::cout << sizeof(x) << '\n';


  std::cout << x.last->price_level << "\t" << x.get_limit_up() << "\n";
  
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "This operation took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " µs\n";
  
  return 0;
}
