#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
constexpr int MAXN = 1030;

int city[MAXN][MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    memset( city, 0, sizeof city );
    int n {}, d {}, best_x {}, best_y {}, best_val {};
    cin >> d >> n;
    for( int i = 0; i < n; ++ i ){
      int x {}, y {}, weight {};
      cin >> x >> y >> weight;
      for( int row = x - d; row <= x + d; ++ row ){
	if( row < 0 or row > 1024 ) continue;
	for( int col = y - d; col <= y + d; ++ col ){
	  if( col < 0 or col > 1024 ) continue;
	  city[row][col] += weight;
	}
      }
    }
    for( int row = 0; row <= 1024; ++ row ){
      for( int col = 0; col <= 1024; ++ col ){
	if( city[row][col] > best_val ){
	  best_val = city[row][col];
	  best_x = row;
	  best_y = col;
	}
      }
    }
    cout << best_x << " " << best_y << " " << best_val << '\n';
  }
  return 0;
}
