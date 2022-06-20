#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
constexpr int MAXN = 110, MAXC = 550;

int N {};
int memo[MAXN][MAXC] {};
int coins[MAXN] {};

int knapsack( int id, int rem_space ){
  if( id == N or rem_space == 0 ) return 0;
  int& ans = memo[id][rem_space];
  if( ans != -1 ) return ans;
  if( coins[id] > rem_space ) return ans = knapsack( id + 1, rem_space );
  return ans = max(
		   knapsack( id + 1, rem_space ),
		   coins[id] + knapsack( id + 1, rem_space - coins[id] ));
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    memset( memo, -1, sizeof memo );
    cin >> N;
    int sum {};
    for( int i = 0; i < N; ++ i ){
      cin >> coins[i];
      sum += coins[i];
    }
    int ans = knapsack( 0, sum / 2 );
    cout << (sum - 2 * ans) << '\n';
  }
  return 0;
}
