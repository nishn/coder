#include <iostream>
int main() {
  short M, D;
  std::cin >> M >> D;
  std::cout << ( M % D == 0 ? "YES" : "NO" ) << std::endl;
}
