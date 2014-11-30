#include <iostream>
#include <vector>

void saiki( unsigned const depth, unsigned const value,
	    unsigned const N,     unsigned const K,     std::vector<std::vector<unsigned>> const& T ) {
  
  if ( depth == N ) {
    if ( value == 0 ) {
      std::cout << "Found" << std::endl;
      exit( 0 );
    }
    return;
  }
  for ( unsigned i = 0; i < K; ++i ) {
    saiki( depth + 1, value ^ T[depth][i] , N, K, T );
  }
}

int main() {
  unsigned N, K;
  std::cin >> N >> K;
  std::vector<std::vector<unsigned>> T( N, std::vector<unsigned>(K) );
  
  for ( unsigned i = 0; i < N; ++i ) {
    for ( unsigned j = 0; j < K; ++j ) {
      std::cin >> T[i][j];
    }
  }

  for ( unsigned i = 0; i < K; ++i ) {
    saiki( 1, T[0][i], N, K, T );
  }
  std::cout << "Nothing" << std::endl;
}
