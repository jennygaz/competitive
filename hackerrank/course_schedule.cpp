#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int courses {}, prerrequisites {};
  vector<int> ts_vals {}, in_degree {};
  vector<vector<int>> adj_list {};
  cin >> courses >> prerrequisites;
  adj_list.assign( courses, vector<int>() );
  in_degree.assign( courses, 0 );
  while( prerrequisites -- ){
    int from_ {}, to_ {};
    cin >> to_ >> from_ ;
    adj_list[from_].emplace_back( to_ );
    ++ in_degree[to_];
  }
  priority_queue<int, vector<int>, greater<int>> pq {};
  for( int from_ {}; from_ < courses; ++ from_ )
    if( in_degree[from_] == 0 )
      pq.emplace( from_ );
  if( pq.empty() ){
    cout << 0 << '\n';
    return 0;
  }
  while( not pq.empty() ){
    int from_ = pq.top();
    pq.pop();
    for( auto& to_ : adj_list[from_] ){
      -- in_degree[to_];
      if( in_degree[to_] > 0 ) continue;
      pq.emplace( to_ );
    }
  }
  if( pq.empty() )
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
  return 0;
}
