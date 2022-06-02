#include <iostream>
#include <unordered_set>

using namespace std;

int tc {}, n {};
int values[20] {};
bool used[20] {};
unordered_set<int> primes { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

inline bool is_prime( int val ){
  return primes.find( val ) != primes.end();
}

void solve( int idx ){
  if( idx == n - 1 and is_prime( values[n - 1] + values[n] ) ){
    for( int i = 0; i < n; ++ i )
      cout << values[i] << (i + 1 == n ? "\n" : " ");
    return;
  }
  for( int i = 2; i <= n; ++ i ){
    if( not used[i] and is_prime( values[idx] + i ) ){
      used[i] = true;
      values[idx + 1] = i;
      solve( idx + 1 );
      used[i] = false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> n ){
    ++ tc;
    if( tc > 1 ) cout << '\n';
    values[0] = values[n] = 1;
    cout << "Case " << tc << ":\n";
    solve(0);
  }
  return 0;
}
