/* UVa 10260 - Soundex */
/* SOlution: Use an array to store the values, check when the previous one is the same so you don't append it */
/* by jennyga */

#include <iostream>

using namespace std;

constexpr int MAXC = 255;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int codes[MAXC] {};
  codes['B'] = codes['F'] = codes['P'] = codes['V'] = 1;
  codes['C'] = codes['G'] = codes['J'] = codes['K'] = codes['Q'] = codes['S'] = codes['X'] = codes['Z'] = 2;
  codes['D'] = codes['T'] = 3;
  codes['L'] = 4;
  codes['M'] = codes['N'] = 5;
  codes['R'] = 6;
  string str {};
  while( cin >> str ){
    int idx {}, prev {};
    while( idx < (int)str.length() ){
      // cerr << "\nidx: " << idx << "\ncurrent: " << str[idx] << "\ncodes[" << str[idx] << "]: " << codes[str[idx]]
      // 	   << "\nprev: " << prev << '\n';
      if( codes[str[idx]] != 0 and codes[str[idx]] != prev )
	cout << codes[str[idx]];
      prev = codes[str[idx]];
      ++ idx;
    }
    cout << '\n';
  }
  return 0;
}
