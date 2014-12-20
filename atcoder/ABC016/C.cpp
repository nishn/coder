#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class USERS{
  std::unordered_map<std::size_t,std::vector<std::size_t> > users;
public:
  USERS( std::size_t const n ) {
    for ( std::size_t i = 1; i <= n; ++i ) {
      users[i] = std::vector<std::size_t>();
    }
  }
  void add_pair( std::size_t const a, std::size_t const b ) {
    users[a].push_back( b );
    users[b].push_back( a );
  }
  std::size_t count_friends( std::size_t const i ) const {
    std::vector<std::size_t> fof;
    for ( auto const id : users.at(i) ) {
      fof.insert( fof.end(), users.at(id).cbegin(), users.at(id).cend() );
    }
    std::sort(fof.begin(), fof.end());
    fof.erase( std::unique( fof.begin(), fof.end() ), fof.end() );

    std::size_t count = 0;
    for ( auto const id : fof ) {
      if ( std::find(users.at(i).cbegin(), users.at(i).cend(), id)  == users.at(i).cend() and id != i ) {
	++count;
      }
    }
    return count;
  }
};

int main() {
  std::size_t N, M;
  std::cin >> N >> M;
  USERS users( N );
  for ( std::size_t i = 0; i < M; ++i ) {
    std::size_t a, b;
    std::cin >> a >> b;
    users.add_pair( a, b );
  }
  for ( std::size_t i = 1; i <= N; ++i ) {
    std::cout << users.count_friends( i ) << std::endl;
  }
}
