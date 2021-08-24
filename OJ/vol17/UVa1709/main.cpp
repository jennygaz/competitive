// UVa 1709 - Amalgamated Artichokes

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
constexpr int MAXN = 1000001;

inline double price( int p, int a, int b, int c, int d, int n, vector<double>& arr ){
  double max_val {-1e6}, max_diff {};
  for( int i = 1; i <= n; ++ i ){
    arr[i] = p * (sin(a * i + b) + cos(c * i + d) + 2);
    if( arr[i] > max_val ) max_val = arr[i];
    if( max_val - arr[i] > max_diff ) max_diff = max_val - arr[i];
  }
  return max_diff;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<double> vals( MAXN, 0 );
  int a {}, b {}, c {}, d {}, n {}, p {};
  while( cin >> p >> a >> b >> c >> d >> n ){
    double ans = price( p, a, b, c, d, n, vals );
    cout << setprecision(6) << fixed << ans << '\n';
  }
  return 0;
}
