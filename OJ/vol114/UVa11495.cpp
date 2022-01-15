/* UVa 11495 - Bubbles and Buckets */
/* Solution: Count inversions in nlogn */
/* by jennyga */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

constexpr int MAXN = 100100;
// Global fenwick tree and storage
int n {};
int vals[MAXN] {}, ft[MAXN] {};

// query the fenwick tree for rsq up to idx
inline int select( int idx ){
  int sum {};
  while( idx > 0 ){
    sum += ft[idx];
    // remove most significant bit
    idx -= (idx & -idx);
  }
  return sum;
}

// update the fenwick tree with the given value at the given position
inline void update( int idx, int val ){
  while( idx < n ){
    ft[idx] += val;
    // adjust all positions that depend on it
    idx += (idx & -idx);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n, n ){
    int inversions {};
    // reset the fenwick tree
    memset( ft, 0, sizeof(ft) );
    for( int i = 0; i < n; ++ i )
      cin >> vals[i];
    // Go from the back to the beginning
    for( int i = n - 1; i >= 0; -- i ){
      // count inversions at point i, querying how many are lesser
      inversions += select( vals[i] - 1 );
      // update the tree for the current value
      update( vals[i], 1 );
    }
    // test the parity of the answer
    cout << (inversions & 1LL ? "Marcelo\n" : "Carlos\n");
  }
  return 0;
}
