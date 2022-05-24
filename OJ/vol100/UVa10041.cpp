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
    for( int i = min_val; i <= max_val; ++ i ){
      int curr_dist {};
      for( int j = 0; j < n; ++ j )
	curr_dist += abs( i - values[j] );
      dist = min( dist, curr_dist );
    }
    cout << dist << '\n';
  }
  return 0;
}
