#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;
constexpr int MAXN = 1000001;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nod( MAXN, 0 ), sequence( MAXN, 0 );
  sequence[0] = 1;
  for( int i = 1; i < MAXN; ++ i )
    for( int j = i; j < MAXN; j += i )
      ++ nod[j];
  for( int i = 1; i < MAXN; ++ i )
    sequence[i] = sequence[i - 1] + nod[sequence[i - 1]];
  int n {};
  cin >> n;
  for( int CASE = 1; CASE <= n; ++ CASE ){
    int a {}, b {};
    cin >> a >> b;
    int dist = distance( lower_bound( sequence.begin(), sequence.end(), a ),
			 upper_bound( sequence.begin(), sequence.end(), b ) );
    cout << "Case " << CASE << ": " << dist << '\n';
  }
  return 0;
}
