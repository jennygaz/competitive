#include <bits/stdc++.h>

using namespace std;
constexpr int MAX_NODES = 1002;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<int> adj_list[MAX_NODES] {};
  int dist[MAX_NODES] {};
  while( tc -- ){
    int nodes {}, edges {}, source_ {};
    cin >> nodes >> edges;
    for( int i = 1; i <= nodes; ++ i )
      adj_list[i].clear();
    while( edges -- ){
      int from_ {}, to_ {};
      cin >> from_ >> to_;
      adj_list[from_].emplace_back( to_ );
      adj_list[to_].emplace_back( from_ );
    }
    cin >> source_;
    memset( dist, 0, sizeof( dist ) );
    bool visited[nodes + 1] {};
    memset( visited, false, sizeof( visited ) );
    queue<int> incoming {};
    incoming.emplace( source_ );
    visited[source_] = true;
    dist[source_] = 0;
    while( not incoming.empty() ){
      int node = incoming.front();
      incoming.pop();
      for( auto& sink_ : adj_list[node] ){
	if( not visited[sink_] ){
	  visited[sink_] = true;
	  dist[sink_] = dist[node] + 6;
	  incoming.emplace( sink_ );
	}
      }
    }
    for( int it = 1; it <= nodes; ++ it ){
      if( it != source_ ){
	if( dist[it] == 0 )
	  cout << "-1 ";
	else
	  cout << dist[it] << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
