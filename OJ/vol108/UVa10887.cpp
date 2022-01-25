/* UVa 10887 - Concatenation of Strings */
/* Solution: Use an unordered_set (HashSet) to keep the real count. Careful with empty strings */
/* by jennyga */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

constexpr int MAXN = 1515;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  vector<string> lhs( MAXN ), rhs( MAXN );
  getline( cin, line );
  tc = stoi( line );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int m {}, n {};
    unordered_set<string> total {};
    getline( cin, line );
    istringstream iss( line );
    iss >> m >> n;
    for( int i = 0; i < m; ++ i )
      getline( cin, lhs[i] );
    for( int i = 0; i < n; ++ i )
      getline( cin, rhs[i] );
    for( int i = 0; i < m; ++ i )
      for( int j = 0; j < n; ++ j )
	total.emplace( lhs[i] + rhs[j] );
    cout << "Case " << CASE << ": " << total.size() << '\n';
  }
  return 0;
}
