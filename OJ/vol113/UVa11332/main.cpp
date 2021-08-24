// UVa 11332 - Summing Digits

#include <iostream>

using namespace std;

// small optimization:
// most sums will be under 100, so we can store them
// saving tons of time for small values
// it can be done for up to 1M too, but might not be needed
constexpr int MAXN = 100;
int sums[MAXN] {};

inline int digits_sum( int n ){
  if( n < MAXN and sums[n] > 0 ) return sums[n];
  else{
    int tmp {}, x {n};
    while( x >= 10 ){
      while( x ){
	tmp += x % 10;
	x /= 10;
      }
      x = tmp;
      tmp = 0;
    }
    if( n < MAXN ) sums[n] = x;
    return x;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n )
    cout << digits_sum( n ) << '\n';
  return 0;
}
