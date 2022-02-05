/* UVa 11136 - Hoax or What */
/* Solution: Use a set to grab the values quickly, since it is a balanced BST */
/* by jennyga */

#include <iostream>
#include <set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    int k {};
    long long ans {};
    multiset<int> keys {};
    for( int i = 0; i < n; ++ i ){
      cin >> k;
      int tmp {};
      for( int j = 0; j < k; ++ j ){
	cin >> tmp;
	keys.insert( tmp );
      }
      auto it_low = keys.begin();
      int low = *it_low;
      keys.erase( it_low );
      auto it_high = keys.end();
      -- it_high;
      int high = *it_high;
      keys.erase( it_high );
      ans += high - low;
    }
    cout << ans << '\n';
  }
  return 0;
}
