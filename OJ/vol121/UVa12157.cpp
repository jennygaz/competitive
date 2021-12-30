/* UVa 12157 - Tariff Plan */
/* Solution: Iterate over all the lengths, add to two variables and get the min of them */
/* by jennyga */

#include <iostream>

using namespace std;

constexpr int MILE_RATE = 30, MILE_COST = 10, JUICE_RATE = 60, JUICE_COST = 15;

inline int min( int lhs, int rhs ){
  return (lhs < rhs ? lhs : rhs );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, val {}, mile {}, juice {};
    cin >> n;
    while( n -- ){
      cin >> val;
      mile += (val / MILE_RATE + 1) * MILE_COST;
      juice += (val / JUICE_RATE + 1) * JUICE_COST;
    }
    cout << "Case " << CASE << ": ";
    if( mile <= juice ) cout << "Mile ";
    if( juice <= mile ) cout << "Juice ";
    cout << min( mile, juice ) << '\n';
  }
  return 0;
}
