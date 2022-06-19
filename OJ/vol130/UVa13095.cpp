#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 100010;
int counts[MAXN][10] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, q {};
  while( cin >> n ){
    for( int i = 1; i <= n; ++ i ){
      int tmp{};
      cin >> tmp;
      for( int d = 0; d < 10; ++ d )
	counts[i][d] = counts[i - 1][d];
      ++ counts[i][tmp];
    }
    cin >> q;
    while( q -- ){
      int L {}, R {};
      cin >> L >> R;
      int total {};
      if( L == R )
	total = 1;
      else{
	for( int i = 0; i < 10; ++ i )
	  total += (counts[R][i] - counts[L - 1][i] > 0);
      }
      cout << total << '\n';
    }
  }
  return 0;
}
