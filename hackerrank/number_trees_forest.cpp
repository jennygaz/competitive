#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> visited {};
unordered_map<int, unordered_set<int>> adj_list {};

void dfs( int from_ ){
  visited[from_] = true;
  for( auto& to_ : adj_list[from_] )
    if( not visited[to_] )
      dfs( to_ );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int edges {};
  cin >> edges;
  while( edges -- ){
    int from_ {}, to_ {};
    cin >> from_ >> to_;
    visited[from_] = visited[to_] = false;
    adj_list[from_].emplace( to_ );
    adj_list[to_].emplace( from_ );
  }
  int forests {};
  for( auto& key_val : visited ){
    if( not visited[key_val.first] ){
      ++ forests;
      dfs( key_val.first );
    }
  }
  cout << forests << '\n';
  return 0;
}
