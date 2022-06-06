#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;
constexpr int MAXN = 505;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int rows {}, cols {};
  vector<vector<int>> grid( MAXN, vector<int>( MAXN, 0 ) );
  while( cin >> rows >> cols, rows | cols ){
    vector<vector<int>> diagonals( rows + cols );
    for( int i = 0; i < rows; ++ i )
      for( int j = 0; j < cols; ++ j )
	cin >> grid[i][j];
    int diag_idx {};
    vector<tuple<int, int>> start_points( rows + cols );
    for( int i = 0; i < cols; ++ i )
      start_points[i] = { 0, i };
    for( int i = 1, idx = cols; i < rows; ++ i, ++ idx )
      start_points[idx] = { i, 0 };
    for( auto& sp : start_points ){
      int x {}, y {};
      std::tie( x, y ) = sp;
      while( x < rows and y < cols ){
	diagonals[diag_idx].emplace_back( grid[x][y] );
	++ x;
	++ y;
      }
      ++ diag_idx;
    }
    int q {};
    cin >> q;
    while( q -- ){
      int a {}, b {};
      cin >> a >> b;
      int max_dist = -1;
      for( int diag = 0; diag < (int)diagonals.size(); ++ diag ){
	if( diagonals[diag].size() == 0 ) continue;
	int curr_dist = distance( lower_bound( diagonals[diag].begin(), diagonals[diag].end(), a ),
				  upper_bound( diagonals[diag].begin(), diagonals[diag].end(), b ) );
	max_dist = max( max_dist, curr_dist );
      }
      cout << max_dist << '\n';
    }
    cout << "-\n";
  }
  return 0;
}
