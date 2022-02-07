/* UVa 1513 - Movie Collection */
/* solution: Use an ordered set, but associate keys to the values given, and reduce them every time */
/* by jennyga */

#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T, typename U = null_type>
using OSTree = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int MAXN = 200200;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int keys[MAXN] {};
  cin >> tc;
  while( tc -- ){
    int movies {}, queries {}, curr_priority {};
    cin >> movies >> queries;
    for( int i = 1; i <= movies; ++ i )
      keys[i] = i;
    OSTree<int> collection( keys + 1, keys + movies );
    while( queries -- ){
      int tmp {};
      cin >> tmp;
      cout << collection.order_of_key( keys[tmp] ) << (queries ? ' ' : '\n');
      collection.erase( keys[tmp] );
      collection.insert( curr_priority );
      keys[tmp] = curr_priority --;
    }
  }
  return 0;
}
