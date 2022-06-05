#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, target {};
  vector<int> values(MAXN);
  while( cin >> n ){
    for( int i = 0; i < n; ++ i )
      cin >> values[i];
    cin >> target;
    sort( values.begin(), values.begin() + n );
    int curr_left {}, curr_right {};
    for( int i = 0; i < n - 1; ++ i ){
      auto it = lower_bound( values.begin() + i + 1, values.begin() + n, target - values[i] );
      if( it != values.end() and *it + values[i] == target ){
	curr_left = i;
	curr_right = it - values.begin();
      }
    }
    cout << "Peter should buy books whose prices are " << values[curr_left] << " and " << values[curr_right] << ".\n\n";
  }
  return 0;
}
