#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int MAXC = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> coins( MAXC );
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i )
      cin >> coins[i];
    int sum {1};
    // there is always at least 2 coins if n > 1
    int total = ( n > 1 ? 2 : 1 );
    // Keep taking coins as long as you can 
    for( int i = 1; i < n - 1; ++ i )
      if( sum + coins[i] < coins[i + 1] ){
	++ total;
	sum += coins[i];
      }
    cout << total << '\n';
  }
  return 0;
}
