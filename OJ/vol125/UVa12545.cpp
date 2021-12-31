/* UVa 12545 - Bits Equalizer */
/* Solution: count ones, and wildcards */
/* by jennyga */

#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string lhs {}, rhs {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    cin >> lhs >> rhs;
    int wildcards {}, wildcards_on_one {}, misplaced_ones {}, misplaced_zeroes {};
    int ones[2] {};
    for( int i = 0; i < (int)lhs.length(); ++ i ){
      if( lhs[i] == '1' ) ++ ones[0];
      else if( lhs[i] == '?' ) ++ wildcards;
      if( rhs[i] == '1' ) ++ ones[1];
      if( lhs[i] == '1' and rhs[i] != '1' ) ++ misplaced_ones;
      if( lhs[i] == '0' and rhs[i] == '1' ) ++ misplaced_zeroes;
      if( lhs[i] == '?' and rhs[i] == '1' ) ++ wildcards_on_one;
    }
    int ans {};
    if( ones[0] > ones[1] ) ans = -1;
    else{
      ans += wildcards;
      ans += max( misplaced_ones, misplaced_zeroes );
    }
    cout << "Case " << CASE << ": " << ans << '\n';
  }
  return 0;
}
