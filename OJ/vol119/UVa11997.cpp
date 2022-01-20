/* UVa 11997 - K Smallest Sums */
/* Solution: Use a priority queue and process all the arrays one after another */
/* by jennyga */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <functional>

constexpr int MAXK = 757, INF = 800 * 1000000;
constexpr int BITMASK = 63; // 00111111, can be used for filling bytes quickly
bool used[MAXK][MAXK] {};
int lhs[MAXK] {}, rhs[MAXK] {};
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k {};
  int curr_vals[MAXK] {}, tmp_vals[MAXK] {}, work_vals[MAXK] {};
  bool used[MAXK][MAXK] {};
  while( cin >> k ){
    memset( lhs, BITMASK, sizeof(int) * MAXK );
    memset( rhs, BITMASK, sizeof(int) * MAXK );
    for( int i = 0; i < k; ++ i )
      cin >> curr_vals[i];
    sort( curr_vals, curr_vals + k );
    for( int n = 1; n < k; ++ n ){
      for( int i = 0; i < k; ++ i )
	cin >> tmp_vals[i];
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq {};
      memset( used, false, sizeof used );
      sort( tmp_vals, tmp_vals + k );
      used[0][0] = true;
      pq.emplace( curr_vals[0] + tmp_vals[0], 0, 0 );
      for( int i = 0; i < k; ++ i ){
	int val {}, x {}, y {};
	tie( val, x, y ) = pq.top();
	pq.pop();
	work_vals[i] = val;
	if( not used[x + 1][y] ){
	  used[x + 1][y] = true;
	  pq.emplace( curr_vals[x + 1] + tmp_vals[y], x + 1, y );
	}
	if( not used[x][y + 1] ){
	  used[x][y + 1] = true;
	  pq.emplace( curr_vals[x] + tmp_vals[y + 1], x, y + 1 );
	}
      } // end for i->k
      for( int i = 0; i < k; ++ i )
	curr_vals[i] = work_vals[i];
      // memcpy( curr_vals, work_vals, sizeof(int) * k );
    } // end for n->k
    for( int i = 0; i < k; ++ i )
      cout << curr_vals[i] << (i + 1 == k ? '\n' : ' ');
  }
  return 0;
}
