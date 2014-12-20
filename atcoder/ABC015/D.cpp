#include <iostream>
#include <vector>

class DP {
  std::vector<std::vector<int>> mat;
  unsigned const W;
  unsigned const K;
  
public:
  DP( unsigned const w, unsigned const k ) : W(w), K(k) {
    mat = std::vector<std::vector<int>>( W+1, std::vector<int>( K+1, -1 ) );
    mat[0][0] = 0;
  }
  void next( int const a, int const b ) {
    auto buff = mat;
    for ( std::size_t j = 0; j <= W; ++j ) {
      for ( std::size_t k = 0; k <= K; ++k ) {
	if ( mat[j][k] != -1 and j + a <= W and k + 1 <= K and buff[j+a][k+1] < mat[j][k] + b ) {
	  buff[j+a][k+1] = mat[j][k] + b;
	}
      }
    }
    mat = buff;
  }
  int max() const {
    int m = 0;
    for ( std::size_t j = 0; j <= W; ++j ) {
      for ( std::size_t k = 0; k <= K; ++k ) {
	if ( m < mat[j][k] ) {
	  m = mat[j][k];
	}
      }
    }
    return m;
  }
};

int main() {
  std::size_t W, N, K;
  std::cin >> W >> N >> K;
  DP dp( W, K );
  for ( std::size_t i = 1; i <= N; ++i ) {
    int a, b;
    std::cin >> a >> b;
    dp.next( a, b );
  }
  std::cout << dp.max() << std::endl;
}
