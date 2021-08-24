// UVa 10424 - Love Calculator

#include <iostream>
#include <iomanip>

using namespace std;

inline int get_string_sum( string& str ){
  int ans {};
  for( auto c : str ){
    if( 'a' <= c and c <= 'z' )
      ans += c - 'a' + 1;
    else if( 'A' <= c and c <= 'Z' )
      ans += c - 'A' + 1;
  }
  return ans;
}

inline int reduce_int( int n ){
  int tmp {};
  while( n >= 10 ){
    while( n ){
      tmp += n % 10;
      n /= 10;
    }
    n = tmp;
    tmp = 0;
  }
  return n;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string lhs {}, rhs {};
  while( getline( cin, lhs ) ){
    getline( cin, rhs );
    int sum_lhs {}, sum_rhs {};
    sum_lhs = get_string_sum( lhs );
    sum_rhs = get_string_sum( rhs );
    sum_lhs = reduce_int( sum_lhs );
    sum_rhs = reduce_int( sum_rhs );
    double ans {};
    if( sum_lhs < sum_rhs )
      ans = 100.0 * sum_lhs / sum_rhs;
    else
      ans = 100.0 * sum_rhs / sum_lhs;
    cout << setprecision(2) << fixed << ans << " %\n";
  }
  return 0;
}
