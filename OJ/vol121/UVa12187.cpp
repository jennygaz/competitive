/* UVa 12187 - Brothers */
/* Solution: Create another matrix, simulate the battles */
/* by jennyga */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

constexpr int MAXDIM = 110;
int ans_grid[MAXDIM][MAXDIM] {}, work_grid[MAXDIM][MAXDIM] {};
int x[4] = {-1, 0, 0, 1}, y[4] = {0, -1, 1, 0};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int heirs {}, rows {}, cols {}, battles {};
  while( cin >> heirs, heirs ){
    cin >> rows >> cols >> battles;
    for( int i = 1; i <= rows; ++ i )
      for( int j = 1; j <= cols; ++ j ){
	cin >> ans_grid[i][j];
	work_grid[i][j] = ans_grid[i][j];
      }
    while( battles -- ){ // simulate the battles
      for( int i = 1; i <= rows; ++ i ){
	for( int j = 1; j <= cols; ++ j ){
	  int curr = (ans_grid[i][j] == heirs - 1 ? 0 : ans_grid[i][j] + 1);
	  for( int k = 0; k < 4; ++ k ){
	    int Y = y[k] + i;
	    int X = x[k] + j;
	    if( ans_grid[Y][X] == curr )
	      work_grid[Y][X] = ans_grid[i][j];
	  }
	}
      }
      for( int i = 1; i <= rows; ++ i )
	for( int j = 1; j <= cols; ++ j )
	  ans_grid[i][j] = work_grid[i][j];
    }
    for( int i = 1; i <= rows; ++ i )
      for( int j = 1; j <= cols; ++ j )
	cout << ans_grid[i][j] << (j == cols ? '\n' : ' ');
  }
  return 0;
}
