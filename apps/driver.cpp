#include <chrono>

#include <hyperbook/hyperbook.h>
#include <hyperbook/Order.h>
#include <hyperbook/OrderBook.h>

int main() {

  Order x {EXECUTION_TYPE::limit, ORDER_TYPE::buy, 0, 634, 100, 10000, 9430};
  Order y {EXECUTION_TYPE::market, ORDER_TYPE::sell, 1, 532, 143, 10512, 10430};
  Order z {EXECUTION_TYPE::limit, ORDER_TYPE::sell, 2, 32, 3443, 1003, 243};

  auto start = std::chrono::high_resolution_clock::now();

  x.print();
  y.print();
  z.print();

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "fmt::print took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " µs\n";
  
  return 0;
}
