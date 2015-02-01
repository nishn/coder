#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>

int main() {

  int N;
  std::cin >> N;

  std::string c;
  std::cin >> c;

  std::array<int,4> count({{0,0,0,0}});
  std::map<char,int> m = {{'1',0},{'2',1},{'3',2},{'4',3}};
  
  for ( int i = 0; i < N; ++i ) {++count[ m[c[i]] ]; }
  
  std::cout << *std::max_element(count.cbegin(), count.cend()) << " "
	    << *std::min_element(count.cbegin(), count.cend()) << std::endl;
}
