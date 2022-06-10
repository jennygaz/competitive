#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;
constexpr int MAXN = 800800;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<tuple<int, int>> jobs( MAXN );
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i ){
      int qty {}, timestamp {};
      cin >> qty >> timestamp;
      jobs[i] = { qty, timestamp };
    }
    sort( jobs.begin(), jobs.begin() + n,
	  []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool {
	    if( get<1>( lhs ) != get<1>( rhs ) )
	      return get<1>( lhs ) < get<1>( rhs );
	    else
	      return get<0>( lhs ) < get<0>( rhs );
	  });
    priority_queue<int> pq {};
    int curr_time {};
    for( int i = 0; i < n; ++ i ){
      int qty = get<0>( jobs[i] ), timestamp = get<1>( jobs[i] );
      pq.emplace( qty );
      curr_time += qty;
      if( curr_time > timestamp ){
	curr_time -= pq.top();
	pq.pop();
      }
    }
    cout << pq.size() << '\n';
    if( tc ) cout << '\n';
  }
  return 0;
}
