#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
constexpr int MAXN = 11, MAXD = 101, MAXK = 220;

int N {}, K {};
int favours_sums[MAXK] {}, costs[MAXK] {};
// state: ( id, items, cost )
int memo[MAXK][MAXN * 2][MAXD * MAXN * MAXN] {};

int knapsack( int id, int items, int cost ){
  if( id == 2 * K or items == 0 or cost == 0 ) return 0;
  int& ans = memo[id][items][cost];
  if( ans != - 1 ) return ans;
  if( costs[id] > cost ) return ans = knapsack( id + 1, items, cost );
  return ans = max( knapsack( id + 1, items, cost ),
		    favours_sums[id] + knapsack( id + 1, items - 1, cost - costs[id] ) );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int max_cost {}, tea_cost {};
  while( cin >> N >> max_cost >> tea_cost >> K, N | K ){
    memset( memo, -1, sizeof memo );
    memset( favours_sums, 0, sizeof favours_sums );
    max_cost *= 10 * (N + 1);
    tea_cost *= 11 * (N + 1);
    for( int i = 0; i < K; ++ i ){
      cin >> costs[i];
      costs[i] *= 11;
      costs[i + K] = costs[i];
      for( int j = 0; j <= N; ++ j ){
	int tmp {};
	cin >> tmp;
	favours_sums[i] += tmp;
      }
      favours_sums[i + K] = favours_sums[i];
    }
    int ans = knapsack( 0, 2 * (N + 1 ), max_cost - tea_cost );
    double res = 1.0 * ans / (N + 1);
    cout << setprecision( 2 ) << fixed << res << '\n';
  }
  memset( memo, -1, sizeof memo );
  return 0;
}
