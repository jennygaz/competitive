#include <iostream>
#include <string>

using namespace std;

constexpr int MAXN = 20;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string grid[MAXN] {};
  int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {};
    cin >> n;
    cout << "Case " << CASE << ":\n";
    for( int i = 0; i < n; ++ i )
      cin >> grid[i];
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	if( grid[i][j] == '.' ){
	  for( int k = 'A'; k <= 'Z'; ++ k ){
	    grid[i][j] = k;
	    int d = 0;
	    for( d = 0; d < 4; ++ d ){
	      if( dir[d][0] + i < 0 or dir[d][0] + i >= n
		  or dir[d][1] + j < 0 or dir[d][1] + j >= n )
		continue;
	      if( grid[i][j] == grid[i + dir[d][0]][j + dir[d][1]] )
		break;
	    }
	    if( d == 4 ) break;
	  }
	}
      }
    }
    for( int i = 0; i < n; ++ i )
      cout << grid[i] << '\n';
  }
  return 0;
}
