#include <array>
#include <iostream>
void dp( std::array<int,41>const& temp, std::array<int,41>& tmp, int const diff, int const j ) {
  int const i = j + diff;
  if ( 0 <= i and i <= 40 and ((tmp[i] != -1 and temp[j] + 1 < tmp[i]) or ! tmp[i] != -1 ) ) {
    tmp[i] = temp[j] + 1;
  }
}

int main() {
  int A, B;
  std::cin >> A >> B;

  std::array<int,41> temp;
  temp.fill(-1);
  temp[A] = 0;

  for ( ;temp[B] == -1; ) {
    std::array<int,41> tmp;
    tmp.fill(-1);
    
    for ( int j = 0; j <= 40; ++j ) {
      if ( temp[j] != -1 ) {
	dp( temp, tmp, -1,  j );
	dp( temp, tmp, -5,  j );
	dp( temp, tmp, -10, j );
	dp( temp, tmp,  1,  j );
	dp( temp, tmp,  5,  j );
	dp( temp, tmp,  10, j );
      }
    }
    temp = tmp;
  }

  std::cout << temp[B] << std::endl;
}
