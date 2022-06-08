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
  vector<tuple<double, int>> values( MAXN );
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    for( int i = 1; i <= n; ++ i ){
      int time {}, cost {};
      cin >> time >> cost;
      values[i - 1] = { -1.0 * cost / time, i };
    }
    sort( values.begin(), values.begin() + n );
    for( int i = 0; i < n; ++ i )
      cout << get<1>( values[i] ) << (i + 1 == n ? "\n" : " ");
    if( tc ) cout << '\n';
  }
  return 0;
}
