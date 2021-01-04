#include <chrono>

#include <hyperbook/hyperbook.h>
#include <hyperbook/Order.h>
#include <hyperbook/OrderBook.h>

int main() {

  Order x {ORDER_TYPE::limit, ORDER_SIDE::buy, 0, 634, 100, 10000, 9430};
  Order y {ORDER_TYPE::market, ORDER_SIDE::sell, 1, 532, 143, 10512, 10430};
  Order z {ORDER_TYPE::limit, ORDER_SIDE::sell, 2, 32, 3443, 1003, 243};

  std::cout << sizeof(x) << "\n";

  auto start = std::chrono::high_resolution_clock::now();

  x.print();
  y.print();
  z.print();

  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "fmt::print took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " µs\n";
  
  return 0;
}
