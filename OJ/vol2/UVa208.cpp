#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;
constexpr int MAXN = 25;

int n {}, target {}, total {};
int adj_mat[MAXN][MAXN] {};
vector<int> route {};
bool used[MAXN] {};

bool reachable( int node ){
  if( node == target ) return true;
  bool ans = false;
  used[node] = true;
  for( int i = 0; i <= n; ++ i )
    if( not used[i] and adj_mat[node][i] )
      ans = ans or reachable( i );
  return ans;
}

void dfs( int node = 1 ){
  if( node == target ){
    route.emplace_back( node );
    for( int i = 0; i < (int)route.size(); ++ i )
      cout << route[i] << (i + 1 == (int)route.size() ? "\n" : " ");
    route.pop_back();
    ++ total;
    return;
  }
  used[node] = true;
  route.emplace_back( node );
  for( int i = 0; i <= n; ++ i ){
    if( not used[i] and adj_mat[node][i] )
      dfs( i );
  }
  route.pop_back();
  used[node] = false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASE = 1;
  while( cin >> target ){
    memset( adj_mat, 0, sizeof adj_mat );
    memset( used, 0, sizeof used );
    total = 0;
    route.clear();
    int from {}, to {};
    while( cin >> from >> to, from | to ){
      adj_mat[from][to] = adj_mat[to][from] = 1;
      if( from > n ) n = from;
      if( to > n ) n = to;
    }
    bool possible = reachable(1);
    memset( used, 0, sizeof used );
    cout << "CASE " << CASE++ << ":\n";
    if( possible )
      dfs( 1 );
    cout << "There are " << total << " routes from the firestation to streetcorner " << target << ".\n";
  }
  return 0;
}
