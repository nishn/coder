#include <iostream>
int main() {
  char ret[2][2] = { { '!', '-' }, { '+', '?' } };
  unsigned A, B, C;
  std::cin >> A >> B >> C;
  std::cout << ret[A + B == C ? 1 : 0][A - B == C ? 1 : 0] << std::endl;
}
