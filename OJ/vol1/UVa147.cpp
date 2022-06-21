#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
constexpr int MAXVAL = 6060, MAXN = 11;

int coins[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long memo[MAXN][MAXVAL] {};

long long ways( int id, int val ){
  if( val == 0 ) return 1;
  if( val < 0 or id == MAXN ) return 0;
  long long& ans = memo[id][val];
  if( ans != -1 ) return ans;
  return ans = ways( id + 1, val ) + ways( id, val - coins[id] );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset( memo, -1, sizeof memo );
  char dot {};
  int dollars {}, cents {};
  while( cin >> dollars >> dot >> cents, dollars | cents ){
    double money = dollars + cents / 100.0;
    dollars *= 20;
    cents /= 5;
    long long ans = ways( 0, dollars + cents );
    cout << setw( 6 ) << setprecision( 2 ) << fixed << right << money
	 << setw( 17 ) << right << ans << '\n';
  }
  return 0;
}
