#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
constexpr int MAXN = 1010, MAXW = 33, MAXP = 110;

int N {}, W {};
int weights[MAXN] {}, prices[MAXN] {};
int memo[MAXW][MAXN] {};

int knapsack( int id, int rw ){
  if( id == N or rw == 0 ) return 0;
  int& ans = memo[rw][id];
  if( ans != -1 ) return ans;
  if( weights[id] > rw ) return knapsack( id + 1, rw );
  return ans = max( knapsack( id + 1, rw ), prices[id] + knapsack( id + 1, rw - weights[id] ) );
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
    for( int i = 0; i < N; ++ i )
      cin >> prices[i] >> weights[i];
    int people {}, total {};
    cin >> people;
    while( people -- ){
      int max_w {};
      cin >> max_w;
      total += knapsack( 0, max_w );
    }
    cout << total << '\n';
  }
  return 0;
}
