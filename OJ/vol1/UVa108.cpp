#include <iostream>

using namespace std;
constexpr int MAXN = 110;
constexpr int MIN_VAL = 127;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int mat[MAXN][MAXN] {};
  cin >> n;
  for( int i = 0; i < n; ++ i )
    for( int j = 0; j < n; ++ j ){
      cin >> mat[i][j];
      if( j > 0 )
	mat[i][j] += mat[i][j - 1];
    }
  int max_rect = MIN_VAL * MIN_VAL * MAXN * (-1);
  for( int left_col = 0; left_col < n; ++ left_col ){
    for( int right_col = left_col; right_col < n; ++ right_col ){
      int curr_rect {};
      for( int row = 0; row < n; ++ row ){
	curr_rect += mat[row][right_col];
	if( left_col > 0 )
	  curr_rect -= mat[row][left_col - 1];
	if( curr_rect < 0 )
	  curr_rect = 0;
	max_rect = max( max_rect, curr_rect );
      }
    }
  }
  cout << max_rect << '\n';
  return 0;
}
