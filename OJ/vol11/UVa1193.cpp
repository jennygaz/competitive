#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, d {}, CASE {};
  vector<tuple<double, double>> intervals( 1010 );
  while( cin >> n >> d, n | d ){
    double x {}, y {};
    bool able {true};
    for( int i = 0; i < n; ++ i ){
      cin >> x >> y;
      if( able and y <= d ){
	double dist = sqrt( d * d - y * y );
	intervals[i] = { x - dist, x + dist };
      }
      else
	able = false;
    }
    cout << "Case " << ++CASE << ": ";
    if( not able ) cout << "-1\n";
    else{
      int total {};
      sort( intervals.begin(), intervals.begin() + n,
	    []( tuple<double, double>& lhs, tuple<double, double>& rhs ) -> bool {
	      if( get<1>( lhs ) == get<1>( rhs ) )
		return get<0>( lhs ) < get<0>( rhs );
	      else
		return get<1>( lhs ) < get<1>( rhs );
	    });
      for( int i = 0; i < n; ){
	int inter {};
	for( inter = 0; inter < n; ++ inter )
	  if( get<0>( intervals[inter] ) > get<1>( intervals[i] ) ) break;
	i = inter;
	++ total;
      }
      cout << total << '\n';
    }
  }
  return 0;
}
