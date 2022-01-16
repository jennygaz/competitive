/* UVa 11933 - Splitting Numbers */
/* Solution: Build A and B by interchanging the ones in N */
/* by jennyga */

#include <iostream>

using namespace std;

constexpr int MAX_BITS = 32;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    bool use_a {true};
    int a {}, b {};
    for( int i = 0; i < MAX_BITS; ++ i ){
      if( n & (1 << i) ){
	if( use_a ){
	  a |= (1 << i);
	  use_a = false;
	}
	else{
	  b |= (1 << i);
	  use_a = true;
	}
      }
    }
    cout << a << " " << b << '\n';
  }
  return 0;
}
