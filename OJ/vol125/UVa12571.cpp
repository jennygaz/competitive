/* UVa 12571 - Brothers and Sisters! */
/* Solution: Precalculate the answers */
/* by jennyga */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

constexpr int MAXQ = 231, MAXN = 100010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int ans[MAXQ] {};
  int vals[MAXN] {};
  cin >> tc;
  while( tc -- ){
    memset( ans, 0, sizeof ans );
    int n {}, q {};
    cin >> n >> q;
    for( int i = 0; i < n; ++ i ){
      cin >> vals[i];
      for( int j = 0; j < MAXQ; ++ j )
	ans[j] = max( ans[j], vals[i] & j );
    }
    while( q -- ){
      cin >> n;
      cout << ans[n] << '\n';
    }
  }
  return 0;
}
