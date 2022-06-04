#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
constexpr int MAX_COLS = 5, MAX_ROWS = 6, MAXK = 8000;

string grid_lhs[MAX_ROWS] {}, grid_rhs[MAX_ROWS] {};
// To keep the coordinates unique, compute them as col * n + row
vector<set<char>> common {};
string pass( 5, 'A' );
int curr_pass {};
vector<string> passwords( MAXK, string( 5, 'A' ) );

void dfs( int curr_col ){
  if( curr_col == MAX_COLS ){
    passwords[curr_pass ++] = pass;
    return;
  }
  for( auto node : common[curr_col] ){
    pass[curr_col] = node;
    dfs( curr_col + 1 );
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int k {};
    cin >> k;
    curr_pass = 1;
    common.assign( 5, set<char>() );
    for( int row = 0; row < MAX_ROWS; ++ row )
      cin >> grid_lhs[row];
    for( int row = 0; row < MAX_ROWS; ++ row )
      cin >> grid_rhs[row];
    // Initialize the common nodes
    for( int col = 0; col < MAX_COLS; ++ col )
      for( int row_lhs = 0; row_lhs < MAX_ROWS; ++ row_lhs )
	for( int row_rhs = 0; row_rhs < MAX_ROWS; ++ row_rhs )
	  if( grid_lhs[row_lhs][col] == grid_rhs[row_rhs][col] )
	    common[col].emplace( grid_lhs[row_lhs][col] );
    // solve the problem
    bool possible = true;
    // prune the search as early as possible
    for( int i = 0; i < MAX_COLS; ++ i )
      possible = possible and (common[i].size() > 0);
    if( not possible ){
      cout << "NO\n";
      continue;
    }
    // Otherwise, try to find all the answers
    dfs( 0 );
    if( k < curr_pass )
      cout << passwords[k] << '\n';
    else
      cout << "NO\n";
  }
  return 0;
}
