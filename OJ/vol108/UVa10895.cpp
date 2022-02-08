/* UVa 10895 - Matrix Transpose */
/* Solution: Use an adjacency list to store them, then iterate through it */
/* by jennyga */

#include <iostream>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int vals[MAXN] {};
  vector<vector<tuple<int, int>>> adj_list( MAXN ), adj_t( MAXN );
  int rows {}, cols {};
  while( cin >> rows ){
    cin >> cols;
    // clear matrix
    for( int row = 1; row <= rows; ++ row )
      adj_list[row].clear();
    // get data
    for( int row = 1; row <= rows; ++ row ){
      adj_list[row].reserve( cols );
      int k {}, tmp {};
      cin >> k;
      for( int i = 0; i < k; ++ i )
	cin >> vals[i];
      for( int i = 0; i < k; ++ i ){
	cin >> tmp;
	adj_list[row].emplace_back( vals[i], tmp ); // emplace index then value
      }
    }
    // generate the transpose
    for( int row = 1; row <= cols; ++ row )
      adj_t[row].clear();
    for( int row = 1; row <= rows; ++ row ){
      for( int idx = 0; idx < (int)adj_list[row].size(); ++ idx ){
	int t_idx {}, val {};
	tie( t_idx, val ) = adj_list[row][idx];
	adj_t[t_idx].emplace_back( row, val );
      }
    }
    // print the transpose
    cout << cols << ' ' << rows << '\n';
    for( int col = 1; col <= cols; ++ col ){
      cout << adj_t[col].size();
      for( int idx = 0; idx < (int)adj_t[col].size(); ++ idx )
	cout << " " << get<0>( adj_t[col][idx] );
      cout << '\n';
      for( int idx = 0; idx < (int)adj_t[col].size(); ++ idx )
	cout << get<1>( adj_t[col][idx] ) << (idx + 1 == adj_t[col].size() ? "" : " ");
      cout << '\n';
    }
  }
  return 0;
}
