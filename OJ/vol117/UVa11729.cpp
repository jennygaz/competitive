#include <iostream>
#include <algorithm>
#include <tuple>
#include <functional>
#include <vector>

using namespace std;
constexpr int MAXN = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, CASE {};
  vector<tuple<int, int>> values( MAXN );
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i ){
      int a {}, b {};
      cin >> a >> b;
      values[i] = { a, b };
    }
    sort( values.begin(), values.begin() + n,
	  []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool {
	    if( get<1>( lhs ) != get<1>( rhs ) )
	      return get<1>( lhs ) > get<1>( rhs );
	    else
	      return get<0>( lhs ) < get<0>( rhs );
	  });
    int a = get<0>( values[0] ), b = get<1>( values[0] ) + a;
    for( int i = 1; i < n; ++ i ){
      a += get<0>( values[i] );
      b = max( b, a + get<1>( values[i] ) );
    }
    cout << "Case " << ++CASE << ": " << b << '\n';
  }
  return 0;
}
