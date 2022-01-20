/* UVa 13190 - Rockabye Tobby */
/* Solution: Use a priority queue and store the periods of each medicine to add them when popped out. Similar to Argus */
/* by jennyga */

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int periods[MAXN] {};
  string names[MAXN] {};
  cin >> tc;
  while( tc -- ){
    int n {}, k {};
    cin >> n >> k;
    int period {}, name {};
    string medicine {};
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq {};
    for( int i = 0; i < n; ++ i ){
      cin >> names[i] >> periods[i];
      pq.emplace( periods[i], i );
    }
    while( k -- ){
      tie( period, name ) = pq.top();
      pq.pop();
      cout << period << " " << names[name] << '\n';
      pq.emplace( period + periods[name], name );
    }
  }
  return 0;
}
