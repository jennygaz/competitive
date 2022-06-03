#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAXN = 55, MAXS = 330;
constexpr char MEMSET_INF = 0x3f;
constexpr int INF = 0x3f3f3f3f;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int coins[MAXN] {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, s {};
    cin >> n >> s;
    for( int i = 1; i <= n; ++ i )
      cin >> coins[i];
    int dp[MAXN][MAXS] {};
    pair<int, int> from[MAXN][MAXS] {};
    memset( dp, MEMSET_INF, sizeof dp );
    dp[0][0] = 0;
    from[0][0] = {-1, -1};
    for( int i = 1; i <= n; ++ i ){
      // init dp, from
      for( int j = 0; j <= s; ++ j ){
	dp[i][j] = dp[i-1][j];
	from[i][j] = from[i-1][j];
      }
      for( int j = coins[i]; j <= s; ++ j ){
	dp[i][j] = min( dp[i][j],
			   min( dp[i][j - coins[i]] + 1, dp[i - 1][j - coins[i]] + 1) );
	if( dp[i][j] == dp[i - 1][j - coins[i]] + 1 )
	  from[i][j] = { i - 1, j - coins[i] };
	if( dp[i][j] == dp[i][j - coins[i]] + 1 )
	  from[i][j] = { i, j - coins[i] };
      }
    } // end dp
    cout << "Case " << CASE << ": ";
    if( dp[n][s] == INF )
      cout << "impossible\n";
    else{
      cout << "[" << dp[n][s] << "]";
      int curr_score = s;
      pair<int, int> it = from[n][s];
      while( it.first != -1 ){
	cout << " " << curr_score - it.second;
	curr_score = it.second;
	it = from[it.first][it.second];
      }
      cout << '\n';
    }
  }
  return 0;
}
