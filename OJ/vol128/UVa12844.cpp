#include <iostream>
#include <algorithm>

using namespace std;
constexpr int MAXW = 10;

int weights[MAXW] {};
inline bool check_sums( int a, int b, int c, int d, int e ){
  return (a + b == weights[0] and a + c == weights[1] and a + d == weights[2] and a + e == weights[3]
	  and b + c == weights[4] and b + d == weights[5] and b + e == weights[6] and c + d == weights[7]
	  and c + e == weights[8] and d + e == weights[9] );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int total {};
    for( int i = 0; i < MAXW; ++ i ){
      cin >> weights[i];
      total += weights[i];
    }
    sort( weights, weights + MAXW );
    cout << "Case " << CASE << ": ";
    int c = total / 4 - weights[0] - weights[9];
    int a = weights[1] - c;
    int b = weights[0] - a;
    int e = weights[8] - c;
    int d = weights[9] - e;
    cout << a << " " << b << " " << c << " " << d << " " << e << '\n';
  }
  return 0;
}
