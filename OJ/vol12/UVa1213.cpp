#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
constexpr int MAXP = 200;
constexpr int MAXN = 1150, MAXK = 20;

bool sieve[MAXN] {};
vector<int> primes( MAXP );
int pidx {}, N {}, K {};
// using it this way so there's better cache locality
// state is (remK, id, remN)
int memo[MAXK][MAXP][MAXN] {};

void atkin(){
  if( MAXN > 2 )
    primes[pidx ++] = 2;
  if( MAXN > 3 )
    primes[pidx ++] = 3;
  for( int i = 0; i < MAXN; ++ i )
    sieve[i] = false;

  for( int x = 1; x * x < MAXN; ++ x ){
    for( int y = 1; y * y < MAXN; ++ y ){
      int n = (4 * x * x) + (y * y);
      if( n <= MAXN and (n % 12 == 1 or n % 12 == 5 ) )
	sieve[n] ^= true;
      n = (3 * x * x ) + (y * y);
      if( n <= MAXN and n % 12 == 7 )
	sieve[n] ^= true;
      n = (3 * x * x) - (y * y);
      if( x > y and n <= MAXN and n % 12 == 11 )
	sieve[n] ^= true;
    }
  }
  for( int r = 5; r * r < MAXN; ++ r )
    if( sieve[r] )
      for( int i = r * r; i < MAXN; i += r * r )
	sieve[i] = false;
  for( int a = 5; a < MAXN; ++ a )
    if( sieve[a] )
      primes[pidx ++] = a;
}

int knapsack( int remK, int id, int remN ){
  // 1. no primes left to add
  if( remN > 0 and remK == 0 ) return 0;
  // if we hit the target
  if( remN == 0 and remK == 0 ) return 1;
  // 2. gone past the target
  // 3. trying to use more primes
  if( remN < 0 or remK < 0 ) return 0;
  // 4. current prime (and beyond) cannot be added
  if( primes[id] > remN ) return 0;
  int& ans = memo[remK][id][remN];
  if( ans != -1 ) return ans;
  // return the sum of the ways while taking id plus the ways of not taking id
  return ans = knapsack( remK - 1, id + 1, remN - primes[id] )
    + knapsack( remK, id + 1, remN );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  atkin();
  memset( memo, -1, sizeof memo );
  while( cin >> N >> K, N | K ){
    int ans = knapsack( K, 0, N );
    cout << ans << '\n';
  }
  return 0;
}
