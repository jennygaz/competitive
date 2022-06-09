#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>

using namespace std;
constexpr int MAXN = 1000100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<tuple<long long, long long>> business( MAXN );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, k {};
    long long ans {};
    cin >> n >> k;
    for( int i = 0; i < n; ++ i ){
      int tmp {};
      cin >> tmp;
      business[i] = { tmp, 0 };
    }
    for( int i = 0; i < n; ++ i ){
      int tmp {}, prev = get<0>( business[i] );
      cin >> tmp;
      business[i] = { prev, tmp };
    }
    sort( business.begin(), business.begin() + n,
	  []( tuple<long long, long long>& lhs, tuple<long long, long long>& rhs ) -> bool {
	    return get<1>( lhs ) - get<0>( lhs ) < get<1>( rhs ) - get<0>( rhs );
	  });
    for( int i = 0; i < n; ++ i ){
      int asked = get<0>( business[i] ), gotten = get<1>( business[i] );
      if( gotten - asked < 0 and k )
	-- k;
      else
	ans += gotten - asked;
    }
    cout << "Case " << CASE << ": ";
    if( ans > 0 )
      cout << ans << '\n';
    else
      cout << "No Profit\n";
  }
  return 0;
}
