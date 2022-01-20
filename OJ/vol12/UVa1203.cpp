/* UVa 1203 - Argus */
/* Solution: Use a priority queue AND enter k times each register */
/* by jennyga */

#include <iostream>
#include <queue>
#include <tuple>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAX_REG = 3030;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string str {};
  int reg {}, per {};
  int periods[MAX_REG] {};
  for( int i = 0; i < MAX_REG; ++ i )
    periods[i] = -1;
  priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
  while( cin >> str, str[0] != '#' ){
    cin >> reg >> per;
    if( periods[reg] == -1 )
      periods[reg] = per;
    pq.emplace( per, reg );
  }
  int k {};
  cin >> k;
  while( k -- ){
    auto tp = pq.top();
    cout << get<1>( tp ) << '\n';
    pq.emplace( get<0>( tp ) + periods[get<1>( tp )], get<1>( tp ) );
    pq.pop();
  }
  return 0;
}
