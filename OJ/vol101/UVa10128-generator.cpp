#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<vector<unsigned long long>>> memo( 15, vector<vector<unsigned long long>>( 15, vector<unsigned long long>( 15, 0 ) ) );
  for( int N = 1; N <= 13; ++ N ){
    vector<int> values( N, 0 );
    for( int idx = 0; idx < N; ++ idx )
      values[idx] = idx + 1;
    do{
      int lhs {1}, rhs {1};
      // left rotation
      int max_val = *values.begin();
      for( auto tmp = values.begin(); tmp != values.end(); ++ tmp )
	if( *tmp > max_val ){
	  ++ lhs;
	  max_val = *tmp;
	}
      // right rotation
      max_val = *values.rbegin();
      for( auto tmp = values.rbegin(); tmp != values.rend(); ++ tmp )
	if( *tmp > max_val ){
	  ++ rhs;
	  max_val = *tmp;
	}
      ++ memo[N][lhs][rhs];
    } while( next_permutation( values.begin(), values.end() ) );
  }
  cout << "{ \n";
  for( int N = 0; N <= 13; ++ N ){
    cout << "{ \n";
    for( int i = 0; i <= 13; ++ i ){
      cout << "{ \n";
      for( int j = 0; j <= 13; ++ j ){
	cout << memo[N][i][j] << (j == 13 ? " " : ", ");
      }
      cout << "}" << (i == 13 ? "\n" : ",\n");
    }
    cout << "}" << (N == 13 ? "\n" : ",\n");
  }
  cout << "\n}";
  return 0;
}
