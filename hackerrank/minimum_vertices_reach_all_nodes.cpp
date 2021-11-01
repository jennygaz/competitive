#include <bits/stdc++.h>

using namespace std;
vector<int> ans {};
vector<vector<int>> adj_list {};
vector<bool> visited {};

void dfs( int from_ ){
  visited[from_] = true;
  for( auto& to_ : adj_list[from_] )
    if( not visited[to_] )
      dfs( to_ );
}

void toposort( int from_ ){
  visited[from_] = true;
  for( auto& to_ : adj_list[from_] )
    if( not visited[to_] )
      toposort( to_ );
  
  ans.emplace_back( from_ );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {};
  cin >> n >> m;
  adj_list.assign( n, vector<int>() );
  while( m -- ){
    int from_ {}, to_ {};
    cin >> from_ >> to_;
    adj_list[from_].emplace_back( to_ );
  }
  visited.assign( n, false );
  for( int source_ {}; source_ < n; ++ source_ )
    if( not visited[source_] )
      toposort( source_ );
  visited.assign( n, false );
  vector<int> vertices {};
  for( auto it = ans.rbegin(); it != ans.rend(); ++ it ){
    if( not visited[*it] ){
      vertices.emplace_back( *it );
      dfs( *it );
    }
  }
  sort( vertices.begin(), vertices.end() );
  for( auto& vertex : vertices )
    cout << vertex << ' ';
  cout << '\n';
  return 0;
}
