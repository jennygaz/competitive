#include <iostream>

using namespace std;
constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int height[MAXN] {};
  int l {}, h {}, r {}, max_r {};
  while( cin >> l >> h >> r ){
    if( r > max_r ) max_r = r;
    for( int i = l; i < r; ++ i )
      if( height[i] < h )
	height[i] = h;
  }
  int prev = 0;
  for( int i = 1; i <= max_r; ++ i )
    if( height[i] != prev ){
      prev = height[i];
      cout << i << " " << height[i] << (i != max_r ? " " : "\n");
    }
  return 0;
}
