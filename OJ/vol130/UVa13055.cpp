/* UVa 13055 - Inception */
/* Solution: Use a stack to simulate the process */
/* by jennyga */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  stack<string> st {};
  cin >> n;
  while( n -- ){
    string tmp {};
    cin >> tmp;
    if( tmp[0] == 'S' ){ // Sleep
      cin >> tmp;
      st.emplace( tmp );
    }
    else if( tmp[0] == 'T' ){ // Test
      if( not st.empty() )
	cout << st.top() << '\n';
      else
	cout << "Not in a dream\n";
    }
    else if( tmp[0] == 'K' ) // Kick
      if( not st.empty() )
	st.pop();    
  }
  return 0;
}
