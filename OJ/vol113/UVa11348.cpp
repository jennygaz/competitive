/* UVa 11348 - Exhibition */
/* Solution: Use bitmasks to check which stamps are only contributed from one person (quickly), or use sets + maps */
/* by jennyga */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <unordered_set>
#include <bitset>

using namespace std;

constexpr int MAXA = 10010, MAXN = 55;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int how_many[MAXN] {};
  long long stamps[MAXA] {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, m {}, tmp {}, keys {};
    memset( stamps, 0, sizeof stamps );
    memset( how_many, 0, sizeof how_many );
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      cin >> m;
      for( int j = 0; j < m; ++ j ){
	cin >> tmp;
	stamps[tmp] |= (1ULL << i);
      }
    }
    for( int i = 0; i < MAXA; ++ i )
      if( __builtin_popcountll( stamps[i] ) == 1 ){
	++ keys;
	for( int j = 0; j < n; ++ j )
	  if( stamps[i] & (1ULL << j) ){
	    ++ how_many[j];
	    break;
	  }
      }
    cout << "Case " << CASE << ":";
    for( int i = 0; i < n; ++ i )
      cout << " " << setprecision( 6 ) << fixed << (100.0 * how_many[i] / keys) << "%";
    cout << '\n';
  }
  return 0;
}
