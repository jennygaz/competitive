#include <iostream>
#include <algorithm>

using namespace std;
constexpr int MAXN = 33;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int eggs[MAXN] {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, p {}, q {};
    cin >> n >> p >> q;
    int total {};
    for( int i = 0; i < n; ++ i ){
      cin >> eggs[i];
      if( p > 0 and q - eggs[i] >= 0 ){
	++ total;
	-- p;
	q -= eggs[i];
      }
    }
    cout << "Case " << CASE << ": " << total << '\n';
  }
  return 0;
}
