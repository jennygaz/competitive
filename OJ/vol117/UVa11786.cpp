/* UVa 11786 - Global Rainings at Bididibus */
/* Solution: Use a stack to process it */
/* by jennyga */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

constexpr char DOWN = '\\', UP = '/';

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){    
    int area {}, level {};
    string str {};
    stack<int> pos {};
    cin >> str;
    for( int i = 0; i < (int)str.length(); ++ i ){
      if( str[i] == DOWN ) pos.push( i );
      else if( str[i] == UP and not pos.empty() ){
	int tmp = pos.top();
	pos.pop();
	area += i - tmp;
      }
    }
    cout << area << '\n';
  }
  return 0;
}
