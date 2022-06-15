#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;
constexpr int NINF = -25 * 25;

int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);  
  int tc;
  string s;
  vector<vector<long>> matrix( 25, vector<long>( 25, 0 ) );
  cin >> tc;
  cin.ignore();
  getline( cin, s );
  while( tc -- ){
    int n = 0;
    while( getline( cin, s ) and s != "" ){
      for( int i = 0; i < (int)s.length(); ++ i ){
        matrix[n][i] = s[i] == '0' ? NINF : 1;
	if( n ) matrix[n][i] += matrix[n - 1][i];
	if( i ) matrix[n][i] += matrix[n][i - 1];
	if( n and i ) matrix[n][i] -= matrix[n - 1][i - 1];
      }
      ++ n;
    }
    int maxArea = 0;
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	for( int k = i; k < n; ++ k ){
	  for( int m = j; m < n; ++ m ){
	    int sub = matrix[k][m];
	    if( i ) sub -= matrix[i - 1][m];
	    if( j ) sub -= matrix[k][j - 1];
	    if( i and j ) sub += matrix[i - 1][j - 1];
	    maxArea = max( maxArea, sub );
	  }
	}
      }
    }
    cout << maxArea << ( tc ? "\n\n" : "\n" );
  }
  return 0;
}
