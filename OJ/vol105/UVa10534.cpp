#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int MAXN = 10010;

int n {};
vector<int> parents, A( MAXN, 0 ), L;

void buildLIS( vector<int>& lis ){\
  L.clear();
  for( int i = 0; i < n; ++ i ){
    int pos = lower_bound( L.begin(), L.end(), A[i] ) - L.begin();
    if( pos == L.size() )
      L.emplace_back( A[i] );
    else
      L[pos] = A[i];
    lis[i] = pos + 1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n ){
    for( int i = 0; i < n; ++ i ) cin >> A[i];
    vector<int> lhs( n, 0 ), rhs( n, 0 );
    buildLIS( lhs );
    for( int i = 0; i < n/2; ++ i )
      swap( A[i], A[n - i - 1] );
    buildLIS( rhs );
    // for( int i = 0; i < n/2; ++ i )
    //   swap( A[i], A[n - i - 1] );
    int ans {1};
    for( int i = 0; i < n; ++ i ){
      int curr_min = min( lhs[i], rhs[n - i - 1] );
      ans = max( ans, curr_min * 2 - 1 );
    }
    cout << ans << '\n';
  }
  return 0;
}
