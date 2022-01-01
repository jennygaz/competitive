/* UVa 11222 - Only I did it! */
/* Solution: Keep hashsets for the intersections, and the problems */
/* by jennyga */

#include <iostream>
#include <unordered_set>
#include <bitset>
#include <algorithm>

using namespace std;
constexpr int STUDENTS = 3, MAX_PROBLEM = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int solved[STUDENTS][MAX_PROBLEM] {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    unordered_set<int> problems {};
    bitset<MAX_PROBLEM> vals[3] {};
    int n {};
    for( int i = 0; i < STUDENTS; ++ i ){
      cin >> n;
      for( int j = 0; j < n; ++ j ){
	cin >> solved[i][j];
	vals[i][solved[i][j]] = 1;
	problems.emplace( solved[i][j] );
      }
    }
    for( auto& problem : problems ){
      int acc = vals[0][problem] + vals[1][problem] + vals[2][problem];
      if( acc > 1 ){
	vals[0][problem] = 0;
	vals[1][problem] = 0;
	vals[2][problem] = 0;
      }
    }
    size_t max_items = max( vals[0].count(), max( vals[1].count(), vals[2].count() ) );
    cout << "Case #" << CASE << ":\n";
    for( int i = 0; i < STUDENTS; ++ i ){
      if( vals[i].count() == max_items ){
	cout << (i + 1) << " " << max_items;
	for( int problem = 0; problem < MAX_PROBLEM; ++ problem )
	  if( vals[i][problem] )
	    cout << " " << problem;
	cout << '\n';
      }
    }
  }
  return 0;
}
