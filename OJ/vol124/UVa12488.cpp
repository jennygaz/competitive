#include <iostream>

using namespace std;
constexpr int MAXN = 30;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int values[MAXN] {}, mapping[MAXN] {}, last_grid[MAXN] {};
  while( cin >> n ){
    for( int i = 0; i < n; ++ i )
      cin >> values[i];
    for( int i = 0; i < n; ++ i )
      mapping[values[i]] = i;
    for( int i = 0; i < n; ++ i )
      cin >> last_grid[i];
    int inversions {};
    for( int i = 0; i < n; ++ i )
      for( int j = i + 1; j < n; ++ j )
	if( mapping[last_grid[j]] < mapping[last_grid[i]] )
	  ++ inversions;
    cout << inversions << '\n';
  }
  return 0;
}
