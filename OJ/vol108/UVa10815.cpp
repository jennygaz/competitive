/* UVa 10815 - Andy's First Dictionary */
/* Solution: You don't need to use a map, a set is enough */
/* by jennyga */

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

constexpr int MAXN = 220;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char buff[MAXN] {};
  set<string> dictionary {};
  while( fgets( buff, MAXN, stdin ) ){
    for( int i = 0; i < MAXN; ++ i ){
      if( buff[i] == '\0' ) break;
      if( 'A' <= buff[i] and buff[i] <= 'Z' )
	buff[i] = 'a' + (buff[i] - 'A');
      if( not( 'a' <= buff[i] and buff[i] <= 'z' ) )
	buff[i] = ' ';
    }
    istringstream iss( buff );
    string key {};
    while( iss >> key ){
      if( key != "" )
	dictionary.emplace( key );
    }
    memset( buff, 0, sizeof buff );
  }
  for( auto& word : dictionary )
    cout << word << '\n';
  return 0;
}
