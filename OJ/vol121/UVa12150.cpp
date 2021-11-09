#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int pos[MAXN] {};
  while( cin >> n, n ){
    memset( pos, 0, sizeof(pos) );
    int idx {}, v {};
    bool valid = true;
    for( int i = 1; i <= n; ++ i ){
      cin >> idx >> v;
      if( not valid ) continue;
      if( i + v > n or i + v <= 0 ) valid = false;
      else if( pos[i + v] != 0 ) valid = false;
      if( valid ) pos[i + v] = idx;
    }
    if( not valid ) cout << "-1\n";
    else{
      for( int i = 1; i <= n; ++ i )
	cout << pos[i] << (i == n ? '\n' : ' ');
    }
  }
  return 0;
}
