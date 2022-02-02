/* UVa 11286 - Conformity */
/* Solution: Create a small hash with all the values given, notice they must be sorted first or the hash function shouldn't care */
/* by jennyga */

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    int vals[5] {};
    unordered_map<long long, int> keys {};
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < 5; ++ j )
	cin >> vals[j];
      sort( vals, vals + 5 );
      long long key {};
      for( int j = 0; j < 5; ++ j )
	key = key * 1000LL + vals[j];
      keys[key] += 1;
    }
    int max_val {};
    int frosh {};
    for( auto& kp : keys )
      if( kp.second > max_val )
	max_val = kp.second;
    for( auto& kp : keys )
      if( kp.second == max_val )
	frosh += kp.second;
    cout << frosh << '\n';
  }
  return 0;
}
