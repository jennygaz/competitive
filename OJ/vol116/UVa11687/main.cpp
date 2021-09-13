/*
 * UVa 11687 - Digits
 */

#include <iostream>

using namespace std;

inline int digits_from_str( string str ){
  int iters {}, curr_digits {}, prev_digits {-1};
  if( str == "1" )
    return 1;
  while( prev_digits != curr_digits ){
    ++ iters;
    prev_digits = curr_digits;
    curr_digits = str.length();
    str = to_string( curr_digits );
  }
  return iters;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  getline( cin, line );
  while( line[0] != 'E' ){
    cout << digits_from_str( line ) << '\n';
    getline( cin, line );
  }
  return 0;
}
