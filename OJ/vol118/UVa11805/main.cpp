// UVa 11805 - Bafana Bafana

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ) {
    int n {}, k {}, p {};
    cin >> n >> k >> p;
    p %= n;
    int ans = (((k - 1) + p) % n) + 1;
    cout << "Case " << CASE << ": " << ans << '\n';
  }
  return 0;
}
