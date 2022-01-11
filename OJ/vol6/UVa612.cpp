/* UVa 612 - DNA Sorting */
/* Solution: Count inversions in a specific way, sort based on that */
/* by jennyga */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

constexpr int MAXN = 110;
int hashed[256] {};

inline int inversions( string &str ){
  int seen[4] {};
  int total {};
  for( int i = (int)str.length() - 1; i >= 0; -- i ){
    int idx = hashed[str[i]];
    ++ seen[idx];
    while( idx ) total += seen[--idx];
  }
  return total;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  hashed['A'] = 0;
  hashed['C'] = 1;
  hashed['G'] = 2;
  hashed['T'] = 3;
  int tc {}, n {}, m {};
  cin >> tc;
  vector<tuple<int, int, string>> vals( MAXN );
  while( tc -- ){
    cin >> m >> n;
    string tmp {};
    for( int i = 0; i < n; ++ i ){
      cin >> tmp;
      int inv = inversions( tmp );
      vals[i] = { inv, i, tmp };
    }
    sort( vals.begin(), vals.begin() + n );
    for( int i = 0; i < n; ++ i )
      cout << get<2>( vals[i] ) << '\n';
    if( tc ) cout << '\n';
  }
  return 0;
}
