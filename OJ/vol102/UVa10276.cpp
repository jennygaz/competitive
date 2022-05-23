#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ans[52] {};
  ans[0] = -1;
  int offset = 2, bit = 1;
  for( int i = 1; i <= 50; ++ i ){
    ans[i] = ans[i - 1] + offset;
    bit ^= 1;
    if( bit ) offset += 2;
  }
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}
