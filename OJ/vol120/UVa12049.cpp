/* UVa 12049 - Just Prune the List */
/* Solution: keep track of the count of each list, then get the min of each count, and substract it from the values of each list */
/* by jennyga */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {}, m {}, tmp {};
    cin >> n >> m;
    unordered_set<int> keys {};
    unordered_map<int, int> lhs {}, rhs {};
    for( int i = 0; i < n; ++ i ){
      cin >> tmp;
      lhs[tmp] += 1;
      keys.emplace( tmp );
    }
    for( int i = 0; i < n; ++ i ){
      cin >> tmp;
      rhs[tmp] += 1;
      keys.emplace( tmp );
    }
    int count {};
    for( auto& key : keys )
      count += max( lhs[key], rhs[key] ) - min( lhs[key], rhs[key] );
    cout << count << '\n';
  }
  return 0;
}
