#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<tuple<int, int>>> valid( 10, vector<tuple<int, int>>() );
  int curr_limit {1};
  for( int curr_case = 2; curr_case < 10; curr_case += 2 ){
    curr_limit *= 10;
    for( int i = 0; i < curr_limit; ++ i )
      for( int j = 0; j < curr_limit; ++ j ){
	int sum = i + j, concat = i * curr_limit + j;
	if( sum * sum == concat )
	  valid[curr_case].emplace_back( i, j );
      }
  }
  int n {};
  while( cin >> n )
    for( auto& sol : valid[n] )
      cout << setw( n / 2 ) << setfill('0') << get<0>( sol )
	   << setw( n / 2 ) << setfill('0') << get<1>( sol )
	   << '\n';
  return 0;
}
