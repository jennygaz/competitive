/* UVa 12650 - Dangerous Dive */
/* Solution: Use a bitset or vector<bool> or array to check if they came back */
/* by jennyga */

#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, r {};
  int divers[MAXN] {};
  while( cin >> n >> r ){
    int tmp {};
    memset( divers, 0, sizeof divers );
    for( int i = 0; i < r; ++ i ){
      cin >> tmp;
      divers[tmp] = 1;
    }
    bool missing = false;
    for( int i = 1; i <= n; ++ i ){
      if( not divers[i] ){
	missing = true;
	cout << i << " ";
      }
    }
    if( not missing )
      cout << "*\n";
    else
      cout << '\n';
  }
  return 0;
}
