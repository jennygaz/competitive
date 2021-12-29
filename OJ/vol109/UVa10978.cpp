/* UVa 10978 - Let's play magic! */
/* solution 1: skip the value */
/* by jennyga */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MAXN = 52; // max ring-buffer size

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string card {}, word {};
  bool used[MAXN] {};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      used[i] = false;
    vector<string> positions( MAXN );
    int curr_pos {-1};
    for( int i = 0; i < n; ++ i ){
      cin >> card >> word;
      int len = word.length();
      while( len ){
	curr_pos = (curr_pos + 1) % n;
	if( not used[curr_pos] ) -- len;
      }
      positions[curr_pos] = card;
      used[curr_pos] = true;
    }
    for( int i = 0; i < n; ++ i )
      cout << positions[i] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
