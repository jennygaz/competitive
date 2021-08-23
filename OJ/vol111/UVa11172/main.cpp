// UVa 11172 - Relational Operators

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int lhs {}, rhs {};
    cin >> lhs >> rhs;
    if( lhs < rhs ) cout << "<\n";
    else if( lhs > rhs ) cout << ">\n";
    else cout << "=\n";
  }
  return 0;
}
