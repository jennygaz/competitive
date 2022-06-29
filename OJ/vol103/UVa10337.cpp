#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAXDIST = 1010, MAXH = 11, INF = 1e9;
int dist {};
int sky[MAXH][MAXDIST] {};
int memo[MAXH][MAXDIST] {};

int dp( int height, int pos ){
  if( height > 9 or height < 0 or pos > dist )
    return INF;
  if( pos == dist )
    return height == 0 ? 0 : INF;
  int& ans = memo[height][pos];
  if( ans != -1 )
    return ans;
  return ans = min( 60 - sky[height][pos] + dp( height + 1, pos + 1 ),
		    min( 30 - sky[height][pos] + dp( height, pos + 1 ),
			 20 - sky[height][pos] + dp( height - 1, pos + 1 ) ) );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    memset( memo, -1, sizeof memo );
    cin >> dist;
    dist /= 100;
    for( int h = 9; h >= 0; -- h )
      for( int i = 0; i < dist; ++ i )
	cin >> sky[h][i];
    cout << dp( 0, 0 ) << "\n\n";
  }
  return 0;
}
