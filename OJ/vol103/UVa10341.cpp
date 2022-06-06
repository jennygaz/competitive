#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
constexpr double EPS = 1e-7;

int p {}, q {}, r {}, s {}, t {}, u {};
inline double f( double x ){
  return p * exp( -x ) + q * sin( x ) + r * cos( x ) + s * tan( x ) + t * x * x + u;
}

inline double df( double x ){
  return (-p) * exp( -x ) + q * cos( x ) - r * sin( x ) + s / (cos( x ) * cos( x )) + 2 * t * x;
}

inline double newton(){
  if( f( 0 ) == 0 ) return 0;
  for( double x0 = 0.5; ; ){
    double x1 = x0 - f( x0 ) / df( x0 );
    if( fabs( x1 - x0 ) < EPS ) return x0;
    x0 = x1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> p >> q >> r >> s >> t >> u ){
    if( f(0) * f(1) > 0 ){
      cout << "No solution\n";
      continue;
    }
    cout << setprecision( 4 ) << fixed << newton() << '\n';
  }
  return 0;
}
