#include <iostream>

int main() {
  unsigned N;
  std::cin >> N;

  unsigned total = 0;
  unsigned count = 0;
  unsigned temp;
  for ( unsigned i = 0; i < N; ++i ) {
    std::cin >> temp;
    if ( temp != 0 ) {
      total += temp;
      ++count;
    }
  }
  std::cout << ( total / count + ( total % count == 0 ? 0 : 1 ) ) << std::endl;
  return 0;
}
