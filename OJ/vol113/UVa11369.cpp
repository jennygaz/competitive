#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 20020;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<int> clothes( MAXN );
  while( tc -- ){
    int n {};
    cin >> n;
    for( int i = 0; i < n; ++ i )
      cin >> clothes[i];
    sort( clothes.begin(), clothes.begin() + n,
	  []( int lhs, int rhs ) -> bool {
	    return lhs > rhs;
	  });
    int discount {};
    for( int i = 2; i < n; i += 3 )
      discount += clothes[i];
    cout << discount << '\n';
  }
  return 0;
}
