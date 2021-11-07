#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <typename T>
inline T abs( T val ){
  return (val >= 0 ? val : -val);
}

constexpr int MAXN = 3003;
int used[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int vals[MAXN] {};
  while( cin >> n ){
    memset( used, 0, sizeof(used) );
    for( int i = 0; i < n; ++ i ){
      cin >> vals[i];
      if( i > 0 )
	++ used[abs(vals[i] - vals[i - 1])];
    }
    bool ans = true;
    for( int i = 1; ans and i < n; ++ i )
      ans = ans and (used[i] > 0);
    cout << (ans ? "Jolly\n" : "Not jolly\n");
  }
  return 0;
}
