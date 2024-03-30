#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

constexpr int MAX_SIZE = 101;
vector<pair<int, int>> directions = {
  { -1, 0 }, { 1, 0 },   // Up, down
  { 0, -1 }, { 0, 1 },   // Left, right
  { -1, -1 }, { -1, 1 }, // upper left, upper right
  { 1, -1 }, { 1, 1 }    // lower left, lower right
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool first_line = false;
  int CASE = 1;
  int rows {}, cols {};
  string line {};
  vector<string> matrix( MAX_SIZE );
  while( getline(cin, line) ) {
    istringstream iss(line);
    iss >> rows >> cols;
    if( !(rows | cols) ) break;
    for( int i = 0; i < rows; ++ i )
      getline( cin, matrix[i] );
    for( int i = 0; i < rows; ++ i ) {
      for( int j = 0; j < cols; ++ j ) {
	if( matrix[i][j] == '*' ) {
	  for( auto& direction: directions ) {
	    if( 0 <= i + direction.first and i + direction.first < rows
		and 0 <= j + direction.second and j + direction.second < cols
		and matrix[i + direction.first][j + direction.second] != '*' ) {
	      ++ matrix[i + direction.first][j + direction.second];
	    }
	  }
	}
      }
    }
    if( first_line ) cout << '\n';
    else first_line = true;
    cout << "Field #" << CASE++ << ":\n";
    for( int i = 0; i < rows; ++ i ) {
      for( int j = 0; j < cols; ++ j ) {
	if( matrix[i][j] == '*' ) cout << '*';
	else cout << (int)(matrix[i][j] - '.');
      }
      cout << '\n';
    }
  }
  return 0;
}
