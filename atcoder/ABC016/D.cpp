#include <iostream>

struct P{
  short x, y;
  P() {}
  P( short const X, short const Y ) {
    x = X;
    y = Y;
  }
};
class LINE{
  P start;
  P end;
  short x_coef, y_coef;
public:
  LINE( P const& s, P const& e ) : start(s), end(e) {
    x_coef = end.y - start.y;
    y_coef = end.x - start.x;
  }
  P s() const { return start; }
  P e() const { return end;   }
  bool side( P const& p ) const {return  y_coef*(p.y - start.y) - x_coef*(p.x - start.x) < 0;}
};
struct COUNTER {
  unsigned char c;
  P first, last;
  LINE chop;
  COUNTER( P const& f, P const& l1, P const& l2 ) : c(0), chop( l1, l2 ) {
    first = f;
    last  = f;
  }
  void add_point( P const& p ) {
    LINE focus( last, p );
    if ( chop.side(last) != chop.side(p) and focus.side( chop.s() ) != focus.side( chop.e() )) {
      ++c;
    }
    last = p;
  }
  short num() {
    add_point( first );
    return c/2 + 1;
  }
};
int main() {
  unsigned short N;
  short x1, y1, x2, y2, x, y;
  std::cin >> x1 >> y1 >> x2 >> y2 >> N >> x >> y;
  COUNTER counter( P(x, y), P( x1, y1 ), P( x2, y2 ) );
  for ( unsigned char i = 1; i < N; ++i ) {
    std::cin >> x >> y;
    counter.add_point( P( x, y ) );
  }
  std::cout << counter.num() << std::endl;
}
