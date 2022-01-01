/* UVa 13048 - Burger Stand */
/* Solution: Linear scan while checking all cells for all conditions. Check conditions carefully */
/* * a. Not any of 'D', 'B', 'S'
 * * b. Not 1 or 2 spots before 'B'
 * * c. Not 1 spot before or after 'S'
 */
/* by jennyga */

#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    cin >> line;
    int ans {};
    for( int i = 0; i < (int)line.length(); ++ i ){
      bool valid = (line[i] != 'D' and line[i] != 'B' and line[i] != 'S');
      if( i > 0 )
	valid = (valid and line[i - 1] != 'S');
      if( i < (int)line.length() )
	valid = (valid and line[i + 1] != 'B' and line[i + 1] != 'S');
      if( i < (int)line.length() - 1 )
	valid = (valid and line[i + 2] != 'B');
      ans += valid;
    }
    cout << "Case " << CASE << ": " << ans << '\n';
  }
  return 0;
}
