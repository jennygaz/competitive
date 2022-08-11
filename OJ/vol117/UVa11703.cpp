#include <iostream>
#include <cmath>

using namespace std;
constexpr int MAXN = 1000100;
constexpr int MOD = 1000000;

int memo[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memo[0] = 1;
  for( int i = 1; i <= 1000000; ++ i ){
    int x = (int)(i - sqrt(i));
    int y = (int)(log(i));
    int z = (int)(i * sin(i) * sin(i));
    memo[i] = (memo[x] + memo[y] + memo[z]) % MOD;
  }
  int n {};
  while( cin >> n, 0 <= n and n <= 1000000 ){
    cout << memo[n] << '\n';
  }
  return 0;
}
