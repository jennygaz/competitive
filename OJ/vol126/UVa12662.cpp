/* UVa 12662 - Good Teacher */
/* solution: Do two linear passes, to compute the distances then the names */
/* by jennyga */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int MAXN = 110;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  vector<string> names( MAXN );
  vector<int> dist( MAXN, 0 );
  cin >> n;
  for( int i = 0; i < n; ++ i ){
    cin >> names[i];
    if( names[i][0] == '?' )
      dist[i] = -1;
  }
  int lhs_idx {}, rhs_idx {};
  // Find leftmost name that isn't a '?'
  while( lhs_idx < n and names[lhs_idx][0] == '?' ) ++ lhs_idx;
  // Mark all previous values
  for( int i = lhs_idx - 1; i >= 0; -- i )
    names[i] = "left of " + names[i + 1];
  // Find the next named index
  rhs_idx = lhs_idx + 1;
  while( rhs_idx < n and names[rhs_idx][0] == '?' ) ++ rhs_idx;
  // Mark the values in-between
  while( rhs_idx < n ){
    for( int i = lhs_idx + 1; i < rhs_idx; ++ i ){
      if( i - lhs_idx == rhs_idx - i )
	names[i] = "middle of " + names[lhs_idx] + " and " + names[rhs_idx];
      else if( i - lhs_idx < rhs_idx - i )
	names[i] = "right of " + names[i - 1];
      else{
	names[i] = names[rhs_idx];
	for( int j = 0; j < rhs_idx - i; ++ j )
	  names[i] = "left of " + names[i];
      }
    }
    lhs_idx = rhs_idx ++;
    while( rhs_idx < n and names[rhs_idx][0] == '?' ) ++ rhs_idx;
  }
  ++ lhs_idx;
  while( lhs_idx < n ){
    names[lhs_idx] = "right of " + names[lhs_idx - 1];
    ++ lhs_idx;
  }
  int q {};
  cin >> q;
  while( q -- ){
    int tmp {};
    cin >> tmp;
    cout << names[tmp - 1] << '\n';
  }
  return 0;
}
