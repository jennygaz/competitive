#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<int> weights( MAXN );
  while( tc -- ){
    int n {}, w {};
    cin >> n >> w;
    for( int i = 0; i < n; ++ i )
      cin >> weights[i];
    sort( weights.begin(), weights.begin() + n );
    int idx {};
    while( idx < n and w > weights[idx] ){
      w -= weights[idx];
      ++ idx;
    }
    cout << idx << '\n';
  }
  return 0;
}
