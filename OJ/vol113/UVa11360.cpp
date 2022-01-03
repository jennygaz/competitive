/* UVa 11360 - Having Fun with Matrices */
/* Solution: Just perform the operations. For faster operations, do the modulo once at the end */
/* by jennyga */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int MAXDIM = 10;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mat[MAXDIM][MAXDIM] {};
  int tc {}, n {}, commands {}, lhs {}, rhs {};
  string line {};
  cin >> tc;
  for( int CASE {1}; CASE <= tc; ++ CASE ){
    cin >> n;
    int sums {};
    for( int i = 0; i < n; ++ i ){
      cin >> line;
      for( int j = 0; j < n; ++ j )
	mat[i][j] = line[j] - '0';
    }
    cin >> commands;
    while( commands -- ){
      cin >> line;
      if( line[0] == 'r' or line[0] == 'c' )
	cin >> lhs >> rhs;
      if( line[0] == 'i' ) ++ sums;
      else if( line[0] == 'd' ) -- sums;
      else if( line[0] == 't' ){ // transpose
	for( int i = 0; i < n; ++ i )
	  for( int j = i; j < n; ++ j )
	    swap( mat[i][j], mat[j][i] );
      }
      else if( line[0] == 'r' ){ // row swap
	-- lhs; -- rhs;
	for( int i = 0; i < n; ++ i )
	  swap( mat[lhs][i], mat[rhs][i] );
      }
      else if( line[0] == 'c' ){ // col swap
	-- lhs; -- rhs;
	for( int i = 0; i < n; ++ i )
	  swap( mat[i][lhs], mat[i][rhs] );
      }
    }
    // increase/decrease modulo 10
    for( int i = 0; i < n; ++ i )
      for( int j = 0; j < n; ++ j )
	mat[i][j] = (mat[i][j] + sums + 1000) % 10;
    // output
    cout << "Case #" << CASE << "\n";
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j )
	cout << mat[i][j];
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}
