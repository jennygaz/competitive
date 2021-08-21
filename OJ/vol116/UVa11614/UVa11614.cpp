// UVa11614: Etruscan Warriors Never Play Chess

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    long long n {};
    cin >> n;
    long long ans = (-1 + sqrt(1 + 8 * n)) / 2;
    cout << ans << '\n';
  }
  return 0;
}
