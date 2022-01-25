/* UVa 11203 - Can you decide it for ME? */
/* Solution: simplify the requirements for the axioms and theorems, it's just a sum */
/* by jennyga */

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string str {};
  cin >> n;
  while( n -- ){
    cin >> str;
    int idx {};
    int qmarks[3] {};
    bool plus {}, equals {}, order {}, bad_char {};
    while( not bad_char and idx < (int)str.length() and str[idx] != 'M' ){
      if( str[idx] == '?' )
	++ qmarks[0];
      else bad_char = true;
      ++ idx;
    }
    if( idx < (int)str.length() and str[idx] == 'M' )
      plus = true;
    ++ idx;
    while( not bad_char and idx < (int)str.length() and str[idx] != 'E' ){
      if( str[idx] == '?' )
	++ qmarks[1];
      else
	bad_char = true;
      ++ idx;
    }
    if( idx < (int)str.length() and str[idx] == 'E' )
      equals = true;
    if( plus and equals ) order = true;
    ++ idx;
    while( not bad_char and idx < (int)str.length() ){
      if( str[idx] == '?' )
	++ qmarks[2];
      else
	bad_char = true;
      ++ idx;
    }
    if( plus and equals and order and not bad_char and qmarks[0] > 0 and qmarks[1] > 0 and qmarks[2] > 0 and qmarks[0] + qmarks[1] == qmarks[2] )
      cout << "theorem\n";
    else
      cout << "no-theorem\n";
  }
  return 0;
}
