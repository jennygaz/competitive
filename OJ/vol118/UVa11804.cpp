#include <iostream>
#include <string>
#include <tuple>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  vector<tuple<int, int, string>> players( 10 );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    string tmp_name {};
    int tmp_off {}, tmp_def {};
    for( int i = 0; i < 10; ++ i ){      
      cin >> tmp_name >> tmp_off >> tmp_def;
      players[i] = { -tmp_off, tmp_def, tmp_name };
    }
    sort( players.begin(), players.end() );
    sort( players.begin(), players.begin() + 5,
	  []( tuple<int, int, string>& lhs, tuple<int, int, string>& rhs ) -> bool {
	    if( get<2>( lhs ) != get<2>( rhs ) ) return get<2>( lhs ) < get<2>( rhs );
	    else if( get<0>( lhs ) != get<0>( rhs ) ) return get<1>( lhs ) < get<1>( rhs );
	    else return get<1>( lhs ) < get<1>( rhs );
	  } );
    sort( players.begin() + 5, players.end(),
	  []( tuple<int, int, string>& lhs, tuple<int, int, string>& rhs ) -> bool {
	    if( get<2>( lhs ) != get<2>( rhs ) ) return get<2>( lhs ) < get<2>( rhs );
	    else if( get<0>( lhs ) != get<0>( rhs ) ) return get<1>( lhs ) < get<1>( rhs );
	    else return get<1>( lhs ) < get<1>( rhs );
	  } );
    cout << "Case " << CASE << ":\n(";
    for( int i = 0; i < 5; ++ i )
      cout << get<2>( players[i] ) << (i + 1 == 5 ? ")\n(" : ", ");
    for( int i = 5; i < 10; ++ i )
      cout << get<2>( players[i] ) << (i + 1 == 10 ? ")\n" : ", ");
  }
  return 0;
}
