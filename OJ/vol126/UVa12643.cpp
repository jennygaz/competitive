/* UVa 12643 - Tennis Rounds */
/* Solution: Use division by 2 repeatedly, check the exponent */
/* by jennyga */

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, i {}, j {}, ans {};
  while( cin >> n >> i >> j ){
    for( int exp = 0; exp < n and i != j; ++ exp ){
      i = (i + 1) >> 1;
      j = (j + 1) >> 1;
      ans = exp + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
