#include <iostream>
#include <cstdlib>
int main() {
  short a, b;
  std::cin >> a >> b;
  short ans = std::abs( a - b );
  std::cout << (ans <= 5 ? ans : 10 - ans) << std::endl;
}
