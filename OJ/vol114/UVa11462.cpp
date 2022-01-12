/* UVa 11462 - Age Sort */
/* Solution: Use bucket sort */
/* by jennyga */

#include <iostream>

using namespace std;
constexpr int MAXN = 100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    int tmp {};
    long ages[MAXN] {};
    for( int i = 0; i < n; ++ i ){
      cin >> tmp;
      ++ ages[tmp];
    }
    int m {n};
    for( int i = 0; i < MAXN and m > 0; ++ i )
      while( ages[i] -- ){
	cout << i << (m > 1 ? " " : "");
	-- m;
      }
    cout << '\n';
  }
  return 0;
}
