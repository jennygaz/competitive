#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 1e4 + 10;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  int producers[MAXN] {}, consumers[MAXN] {}, both[MAXN * 2] {};
  while( tc -- ){
    int p {}, c {}, b {1};
    cin >> p >> c;
    for( int i = 0; i < p; ++ i ){
      cin >> producers[i];
      both[b ++] = producers[i];
    }
    for( int i = 0; i < c; ++ i ){
      cin >> consumers[i];
      both[b ++] = consumers[i];
    }
    sort( producers, producers + p );
    sort( consumers, consumers + c );
    sort( both, both + b );
    int cost {}, angry {12345678};
    for( int i = 0; i < b; ++ i ){
      int lhs {}, rhs {};
      while( lhs < p and producers[lhs] <= both[i] ) ++ lhs;
      while( rhs < c and consumers[rhs] < both[i] ) ++ rhs;
      int dist = p - lhs + rhs;
      if( dist < angry ){
	angry = dist;
	cost = both[i];
      }
    }
    cout << cost << " " << angry << '\n';
  }
  return 0;
}
