/* UVa 13212 - How Many Inversions? */
/* Solution: Count the inversion with an O(nlogn) method, here I use modified mergesort */
/* by jennyga */

#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 1000010; // 1e6 + offset
int n {};
int vals[MAXN] {}, tmp[MAXN] {};

long long merge( int lhs, int mid, int rhs ){
  int i {}, j {}, k {};
  long long inversions {};
  i = lhs; j = mid; k = lhs;
  while( i <= mid - 1 and j <= rhs ){
    if( vals[i] <= vals[j] )
      tmp[k ++] = vals[i ++];
    else{
      tmp[k ++] = vals[j ++];
      inversions += mid - i;
    }
  }
  while( i <= mid - 1 )
    tmp[k ++] = vals[i ++];
  while( j <= rhs )
    tmp[k ++] = vals[j ++];
  for( int i = lhs; i <= rhs; ++ i )
    vals[i] = tmp[i];
  return inversions;
}

long long mergesort( int lhs, int rhs ){
  int mid {};
  long long inversions {};
  if( lhs < rhs ){
    mid = (lhs + rhs) / 2;
    inversions += mergesort( lhs, mid );
    inversions += mergesort( mid + 1, rhs );
    inversions += merge( lhs, mid + 1, rhs );
  }
  return inversions;
}

inline long long count_inversions( int n ){
  return mergesort( 0, n - 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      cin >> vals[i];
    cout << count_inversions( n ) << '\n';
  }
  return 0;
}
