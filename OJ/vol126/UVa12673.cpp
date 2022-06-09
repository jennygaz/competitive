#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;
constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, goals {};
  vector<tuple<int, int>> matches( MAXN );
  while( cin >> n >> goals ){
    int a {}, b {};
    for( int i = 0; i < n; ++ i ){
      cin >> a >> b;
      matches[i] = { a, b };
    }
    sort( matches.begin(), matches.begin() + n,
	  []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool {
	    return (get<0>( lhs ) - get<1>( lhs )) > (get<0>( rhs ) - get<1>( rhs ));
	  });
    int total_pts {};
    for( int i = 0; i < n; ++ i ){
      a = get<0>( matches[i] );
      b = get<1>( matches[i] );
      if( a > b ) total_pts += 3;
      else if( a == b ){
	if( goals ){
	  total_pts += 3;
	  -- goals;
	}
	else
	  ++ total_pts;
      }
      else if( goals > b - a ){
	goals -= b - a + 1;
	total_pts += 3;
      }
      else if( goals == b - a ){
	goals -= b - a;
	++ total_pts;
      }
    }
    cout << total_pts << '\n';
  }
  return 0;
}
