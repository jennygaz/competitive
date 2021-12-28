/* UVa 11559 - Event Planning */
/* Solution: Just check the boundaries and get the min cost */
/* by jennyga */

#include <iostream>

using namespace std;
constexpr int MAX_COST = 500000 * 200 + 1;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, budget {}, hotels {}, weeks {};
  while( cin >> n >> budget >> hotels >> weeks ){
    int min_cost = MAX_COST;
    int cost {}, available {};
    for( int i = 0; i < hotels; ++ i ){
      cin >> cost;
      for( int j = 0; j < weeks; ++ j ){
	cin >> available;
	if( n <= available and n * cost <= budget and n * cost < min_cost )
	  min_cost = n * cost;
      }
    }
    if( min_cost == MAX_COST ) cout << "stay home\n";
    else cout << min_cost << '\n';
  }
  return 0;
}
