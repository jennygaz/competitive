#include <iostream>
#include <algorithm>

using namespace std;

int n {5};
int values[5] {};

bool possible( int total, int pos ){
  if( pos == n )
    return total == 23;
  return possible( total + values[pos], pos + 1 )
    or possible( total - values[pos], pos + 1 )
    or possible( total * values[pos], pos + 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while( cin >> values[0], values[0] ){
    for( int i = 1; i < n; ++ i )
      cin >> values[i];
    sort( values, values + n );
    bool ans = false;
    do {
      if( ans ) break;
      ans = possible( values[0], 1 );
    } while( next_permutation( values, values + n ) );
    cout << (ans ? "Possible\n" : "Impossible\n");
  }
  return 0;
}
