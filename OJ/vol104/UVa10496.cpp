#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAXN = 11;

int x[MAXN], y[MAXN] {};
int dist[MAXN][MAXN] {};
int memo[MAXN][1<<MAXN] {};

int tsp( int u, int mask ){
  if( mask == 0 ) return dist[u][0];
  int& ans = memo[u][mask];
  if( ans != -1 ) return ans;
  ans = 2e9;
  int m = mask;
  while( m ){
    int two_pow_v = (m & -(m));
    int v = __builtin_ctz( two_pow_v ) + 1;
    ans = min( ans, dist[u][v] + tsp( v, mask ^ two_pow_v ) );
    m -= two_pow_v;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    memset( memo, -1, sizeof memo );
    int n {}, m {};
    cin >> n >> m;
    cin >> x[0] >> y[0];
    int b {};
    cin >> b;
    for( int i = 1; i <= b; ++ i )
      cin >> x[i] >> y[i];
    for( int i = 0; i <= b; ++ i )
      for( int j = i + 1; j <= b; ++ j )
	dist[i][j] = dist[j][i] = abs( x[i] - x[j] ) + abs( y[i] - y[j] );
    cout << "The shortest path has length " << tsp( 0, (1<<b) - 1 ) << '\n';
  }
  return 0;
}
