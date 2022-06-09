#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<int> heights( MAXN );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, max_height {}, solo_time {}, carry_time {};
    cin >> n >> max_height >> solo_time >> carry_time;
    for( int i = 0; i < n; ++ i )
      cin >> heights[i];
    sort( heights.begin(), heights.begin() + n );
    // find the first value that cannot be paired with the minimum height
    auto rhs = upper_bound( heights.begin(), heights.begin() + n, max_height - heights[0] - 1 );
    -- rhs;
    auto lhs = heights.begin();
    int pairs {}, ans {};
    if( carry_time >= 2 * solo_time )
      ans = n * solo_time;
    else{
      while( lhs < rhs ){
	while( lhs < rhs and *lhs + *rhs >= max_height ) -- rhs;
	if( lhs < rhs and *lhs + *rhs < max_height ){
	  ++ pairs;
	  ++ lhs;
	}
	-- rhs;
      }
      ans = pairs * carry_time + solo_time * (n - 2 * pairs);
    }
    cout << "Case " << CASE << ": " << ans << '\n';
  }
  return 0;
}
