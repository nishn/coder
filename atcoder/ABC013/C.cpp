#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

class COST {
  double N, H, A, B, C, D, E;
  double x_coef, y_coef, H_NE;
public:
  COST( double const n, double const h, double const a, double const b,
	double const c, double const d, double const e ):N(n), H(h), A(a), B(b), C(c), D(d), E(e) {
    x_coef = B+E;
    y_coef = D+E;
    H_NE   = H - N*E;
    std::cout << std::fixed << std::setprecision(0)
	      << (H_NE > 0 ? 0 : search( std::ceil( -H_NE/x_coef ) + 1.0 , 0.0 ))
	      << std::endl;
  }
  double cost( double const x, double const y ) const {
    return A*x + C*y;
  }
  bool hungry_check( double const x, double const y ) const {
    return x_coef*x + y_coef*y + H_NE > 0;
  }
  double search( double const x, double const y ) const {
    double min_cost = std::numeric_limits<double>::max();
    for( double tmp_x = x, tmp_y = y; 0 <= tmp_x ; --tmp_x ) {
      for ( ;; ++tmp_y ) {
	if ( hungry_check( tmp_x, tmp_y ) ) {
	  double tmp_cost = cost( tmp_x, tmp_y );
	  if ( tmp_cost < min_cost ) { min_cost = tmp_cost; }
	  break;
	}
      }
    }
    return min_cost;
  }
};

int main() {
  double N, H, A, B, C, D, E;
  std::cin >> N >> H >> A >> B >> C >> D >> E;
  COST c( N, H, A, B, C, D, E);
}
