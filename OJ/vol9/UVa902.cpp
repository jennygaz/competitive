/* UVa 902 - Password Search */
/* Solution: Just create an unordered_map and keep track of the max count */
/* by jennyga */

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string str {};
  while( cin >> n ){
    cin >> str;
    unordered_map<string, int> vals {};
    for( int i = 0; i <= (int)str.length() - n; ++ i )
      vals[str.substr( i, n )] += 1;
    int max_val {};
    for( auto& kp : vals )
      if( kp.second > max_val ){
	max_val = kp.second;
	str = kp.first;
      }
    cout << str << '\n';
  }
  return 0;
}
