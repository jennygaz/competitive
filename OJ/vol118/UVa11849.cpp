/* UVa 11849 - CD */
/* Solution: Use two unordered sets and check the differences */
/* Improvement: Use something faster and optimized for set operations. Even a middle set with all the common keys could be a good first optimization */
/* Improvement: Use `set` with `emplace_hint` since they're ordered */
/* by jennyga */

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {};
  while( cin >> n >> m, n | m ){ 
    int tmp {}, count {};
    unordered_map<int, int> hashes {};
    for( int i = 1; i <= n; ++ i ){
      cin >> tmp;
      hashes[tmp] = i;
    }
    for( int i = 0; i < m; ++ i ){
      cin >> tmp;
      if( hashes[tmp] > 0 )
	++ count;
    }
    cout << count << '\n';
  }
  return 0;
}
