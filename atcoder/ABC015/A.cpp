#include <iostream>
#include <string>

int main() {
  std::string A, B;
  std::cin >> A >> B;
  std::cout << ( A.size() < B.size() ? B : A ) << std::endl;
  return 0;
}
