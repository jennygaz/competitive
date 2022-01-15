/* UVa 10264 - The Most Potent Corner */
/* Solution: Use bitmasks appropriately, there is a pattern with the corners */
/* by jennyga */

#include <iostream>

using namespace std;

constexpr int MAXN = 16;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int weights[1 << MAXN] {};
  int n {};
  while( cin >> n ){
    int potency[1 << MAXN] {};
    for( int i = 0; i < (1 << n); ++ i )
      cin >> weights[i];
    // compute the potency of each corner
    for( int i = 0; i < (1 << n); ++ i )
      // add the weight of all neighbours by toggling bits one at a time
      for( int j = 0; j < n; ++ j )
	potency[i] += weights[ i ^ (1 << j) ];
    // Now, compute the pair of neighboring potencies that is the greatest
    int max_pot {};
    for( int i = 0; i < (1 << n); ++ i ){
      for( int j = 0; j < n; ++ j ){
	int tmp = potency[i] + potency[ i ^ (1 << j) ];
	if( tmp > max_pot )
	  max_pot = tmp;
      }
    }
    cout << max_pot << '\n';
  }
  return 0;
}
