/* UVa 10258 - Contest Scoreboard */
/* Solution: Use a tuple/struct to automatically sort the values */
/* by jennyga */

#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <cstdlib>

using namespace std;
constexpr int MAXN = 110, MAXP = 10;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  getline( cin, line );
  while( tc -- ){
    int penalty[MAXN][MAXP] {}, solved[MAXN][MAXP] {}, seen[MAXN] {}, total_penalty[MAXN] {};
    while( getline( cin, line ), line != "" ){
      istringstream iss( line );
      int team {}, problem {}, time_taken {};
      char verdict {};
      iss >> team >> problem >> time_taken >> verdict;
      seen[team] = 1;
      if( verdict == 'I' )
	penalty[team][problem] += 20;
      if( verdict == 'C' ){
	if( not solved[team][problem] ){
	  solved[team][problem] = 1;
	  total_penalty[team] += penalty[team][problem] + time_taken;
	}
      }
    } // end while
    vector<tuple<int, int, int>> participants;
    for( int i = 0; i < MAXN; ++ i ){
      if( seen[i] ){
	int score {};
	for( int j = 0; j < MAXP; ++ j )
	  if( solved[i][j] ) ++ score;
	participants.emplace_back( i, score, total_penalty[i] );
      }
    }
    sort( participants.begin(), participants.end(), []( tuple<int, int, int> &lhs, tuple<int, int, int> &rhs ) -> bool {
      if( get<1>( lhs ) != get<1>( rhs ) ) return get<1>( lhs ) > get<1>( rhs );
      else if( get<2>( lhs ) != get<2>( rhs ) ) return get<2>( lhs ) < get<2>( rhs );
      else return get<0>( lhs ) < get<0>( rhs );
    });
    for( auto& part : participants )
      cout << get<0>( part ) << " " << get<1>( part ) << " " << get<2>( part ) << '\n';
    if( tc ) cout << '\n';
  }
  return 0;
}
