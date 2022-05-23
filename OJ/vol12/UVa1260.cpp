#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAXN = 5050;

int ft_size = MAXN;
int ft[MAXN] {};

// update nodes that depend on i, by delta
void update( int i, int delta ){
  while( i < ft_size ){
    ft[i] += delta;
    i |= i + 1;
  }
}

// sum of [0, r]
int sum( int r ){
  int res = 0;
  while( r >= 0 ){
    res += ft[r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}

// sum of [l, r]
int sum( int l, int r ){
  return sum(r) - sum(l - 1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int vals[MAXN] {};
  cin >> tc;
  while( tc -- ){
    memset( ft, 0, sizeof ft );
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i )
      cin >> vals[i];
    int not_inversions {};
    for( int i = 0; i < n; ++ i ){
      // to count non-inversions we need the sum up to the value
      not_inversions += sum( vals[i] );
      // then we update. We use the value since we want to count equal values too
      update( vals[i], 1 );
    }
    cout << not_inversions << '\n';
  }
  return 0;
}
