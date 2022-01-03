/* UVa 12709 - Falling Ants */
/* Solution: Sort by H then by the product LW */
/* by jennyga */

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;

constexpr int MAXN = 110;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  vector<tuple<int, int, int>> data( MAXN );
  while( cin >> n, n ){
    int L {}, W {}, H {};
    for( int i = 0; i < n; ++ i ){
      cin >> L >> W >> H;
      data[i] = { L, W, H };
    }
    sort( data.begin(), data.begin() + n,
	  []( tuple<int, int, int>& lhs, tuple<int, int, int>& rhs ) -> bool {
	    if( get<2>( lhs ) != get<2>( rhs ) ) return get<2>( lhs ) > get<2>( rhs );
	    else return get<0>( lhs ) * get<1>( lhs ) > get<0>( rhs ) * get<1>( rhs );
	  } );
    cout << get<0>( data[0] ) * get<1>( data[0] ) * get<2>( data[0] ) << '\n';
  }
  return 0;
}
