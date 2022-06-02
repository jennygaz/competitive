#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {}, h {};
    cin >> n >> h;
    for( int mask = 1; mask < (1 << n); ++ mask ){
      if( __builtin_popcount( mask ) == h ){
	for( int i = n - 1; i >= 0; -- i )
	  cout << (mask & (1 << i) ? 1 : 0);
	cout << '\n';
      }
    }
    if( tc ) cout << '\n';
  }
  return 0;
}
