#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tup[3] {};
  unorderes_set<int> values {};
  for( int i = 0; i <= 20; ++ i ){
    values.emplace( i );
    values.emplace( i * 2 );
    values.emplace( i * 3 );
  }
  values.emplace( 50 );
  int n {};
  while( cin >> n, n > 0 ){
    set<tuple<int, int, int>> combinations, permutations;
    for( auto& i : values ){
      for( auto& j : values ){
	for( auto& k : values ){
	  if( i + j + k == n ){
	    tup[0] = i;
	    tup[1] = j;
	    tup[2] = k;
	    sort( tup, tup + 3);
	    combinations.emplace( tup[0], tup[1], tup[2] );
	    permutations.emplace( i, j, k );
	  }
	}
      }
    }
    if( combinations.size() == 0 and permutations.size() == 0 )
      cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
    else{
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinations.size() << ".\n";
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations.size() << ".\n";
    }
    cout << "**********************************************************************\n";
  }
  cout << "END OF OUTPUT\n";
  return 0;
}
