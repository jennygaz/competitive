// UVa 11547 - Automatic Answer

#include <iostream>

using namespace std;

inline long ans( int n ){
  long tmp = 315L * n + 36962L;
  return (tmp >= 0 ? tmp : -tmp);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    cout << (ans( n ) / 10) % 10 << '\n';
  }
  return 0;
}
