/* UVa 11577 - Letter Frequency */
/* Solution: Count the max frequency, output the highest ocurring characters */
/* by jennyga */

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
constexpr int MAXC = 256;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int freqs[MAXC] {}, codes[MAXC] {};
  for( int i = 'A'; i <= 'Z'; ++ i )
    codes[i] = 'a' + (i - 'A');
  for( int i = 'a'; i <= 'z'; ++ i )
    codes[i] = i;
  string line {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    memset( freqs, 0, sizeof freqs );
    getline( cin, line );
    for( int i = 0; i < (int)line.length(); ++ i )
      ++ freqs[codes[line[i]]];
    int max_freq {};
    for( int i = 0; i < MAXC; ++ i )
      if( (('a' <= i and i <= 'z') or ('A' <= i and i <= 'Z')) and max_freq < freqs[i] )
	max_freq = freqs[i];
    for( int i = 'a'; i <= 'z'; ++ i )
      if( freqs[i] == max_freq )
	cout << (char)(i);
    cout << '\n';
  }
  return 0;
}
