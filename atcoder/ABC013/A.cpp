#include <iostream>

int main() {
  char X;
  std::cin >> X;
  std::cout << (short)(X - 'A' + 1) << std::endl;
}
