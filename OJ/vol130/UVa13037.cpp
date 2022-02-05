/* UVa 13037 - Chocolate */
/* Solution: Use sets, or a map of vectors */
/* by jennyga */

#include <iostream>
#include <unordered_map>
#include <array>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    unordered_map<int, array<int, 3>> chocolates {};
    int L {}, R {}, S {}, tmp {};
    cin >> L >> R >> S;
    for( int i = 0; i < L; ++ i ){
      cin >> tmp;
      chocolates[tmp][0] = 1;
    }
    for( int i = 0; i < R; ++ i ){
      cin >> tmp;
      chocolates[tmp][1] = 1;
    }
    for( int i = 0; i < S; ++ i ){
      cin >> tmp;
      chocolates[tmp][2] = 1;
    }
    vector<int> uniq[3] {}, exclude[3] {};
    for( auto& kp : chocolates ){
      int bitmask = kp.second[0] | (kp.second[1] << 1) | (kp.second[2] << 2);
      if( bitmask == 1 ) // only L
	uniq[0].emplace_back( kp.first );
      else if( bitmask == 2 ) // only R
	uniq[1].emplace_back( kp.first );
      else if( bitmask == 4 ) // only S
	uniq[2].emplace_back( kp.first );
      else if( bitmask == 6 ) // not L
	exclude[0].emplace_back( kp.first );
      else if( bitmask == 5 ) // not R
	exclude[1].emplace_back( kp.first );
      else if( bitmask == 3 ) // not S
	exclude[2].emplace_back( kp.first );
    }
    cout << "Case #" << CASE << ":\n";
    for( int i = 0; i < 3; ++ i )
      cout << uniq[i].size() << " " << exclude[i].size() << '\n';
  }
  return 0;
}
