#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAXVAL = 7500, MAXN = 5;

int coins[MAXN] = {1, 5, 10, 25, 50};
long long memo[MAXN][MAXVAL] {};

long long ways( int id, int val ){
  if( val == 0 ) return 1;
  if( val < 0 or id == MAXN ) return 0;
  long long& ans = memo[id][val];
  if( ans != -1LL ) return ans;
  return ans = ways( id + 1, val ) + ways( id, val - coins[id] );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset( memo, -1, sizeof memo );
  int val {};
  while( cin >> val )
    cout << ways( 0, val ) << '\n';
  return 0;
}
