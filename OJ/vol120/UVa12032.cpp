#include <iostream>

using namespace std;
constexpr int MAXN = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int vals[MAXN] {};
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, k {}, res {};
    cin >> n;
    for( int i = 1; i <= n; ++ i )
      cin >> vals[i];
    k = 0;
    for( int i = 1; i <= n; ++ i )
      if( vals[i] - vals[i - 1] > k )
	k = vals[i] - vals[i - 1];
    res = k;
    for( int i = 1; i <= n; ++ i ){
      if( vals[i] - vals[i - 1] == k )
	-- k;
      else if( vals[i] - vals[i - 1] > k ){
	++ res;
	break;
      }
    }
    cout << "Case " << CASE << ": " << res << '\n';
  }
  return 0;
}
