#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
constexpr int MAXN = 2020;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, max_chars {}, max_lines {};
  string words[MAXN] {};
  while( cin >> n >> max_lines >> max_chars ){
    for( int i = 0; i < n; ++ i )
      cin >> words[i];
    int idx {}, lines {};
    bool first {};
    while( idx < n ){
      int curr_c = 0;
      first = false;
      while( curr_c <= max_chars ){
	if( (int)words[idx].length() + curr_c + first <= max_chars ){
	  curr_c += (int)words[idx ++].length() + first;
	  first = true;
	}
	else
	  break;
      }
      ++ lines;
    }
    cout << ceil( 1.0 * lines / max_lines ) << '\n';
  }
  return 0;
}
