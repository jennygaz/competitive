#include <iostream>
#include <algorithm>

using namespace std;
constexpr int MAXN = 30300;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  int values[MAXN] {};
  while( tc -- ){
    int n {}, min_val {MAXN}, max_val {};
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      cin >> values[i];
      if( values[i] < min_val )
	min_val = values[i];
      if( values[i] > max_val )
	max_val = values[i];
    }
    int dist = MAXN * MAXN;
    nth_element( values, values + n/2, values + n );
    int left_dist {}, right_dist {};
    for( int i = 0; i < n; ++ i )
      left_dist += abs( values[i] - values[n/2] );
    nth_element( values, values + n/2 + 1, values + n );
    for( int i = 0; i < n; ++ i )
      right_dist += abs( values[i] - values[n/2 + 1] );
    dist = min( left_dist, right_dist );
    cout << dist << '\n';
  }
  return 0;
}
