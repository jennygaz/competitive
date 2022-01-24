/* UVa 1368 - DNA Consensus String */
/* Solution: Build a string based on the max number of tokens for each space, in lexicographical order */
/* by jennyga */

#include <iostream>
#include <cstring>

using namespace std;
constexpr int MAXL = 1010, MAXN = 55, MAXASCII = 256;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  string strs[MAXN] {};
  // small hashmap
  int codes[MAXASCII] {};
  codes['A'] = 0;
  codes['C'] = 1;
  codes['G'] = 2;
  codes['T'] = 3;
  // to keep the counts of all the characters
  int counts[MAXL][4] {};
  while( tc -- ){
    int n {}, m {};
    cin >> n >> m;
    memset( counts, 0, sizeof counts );
    for( int i = 0; i < n; ++ i )
      cin >> strs[i];
    // TO-DO: Check this part so you count correctly AND use the proper value in the next step
    for( int i = 0; i < n; ++ i )
      for( int j = 0; j < m; ++ j )
	++ counts[j][codes[strs[i][j]]];
    int consensus_error {};
    string ans {};
    for( int i = 0; i < m; ++ i ){
      if( counts[i][0] >= counts[i][1] and counts[i][0] >= counts[i][2] and counts[i][0] >= counts[i][3] ){
	cout << 'A';
	consensus_error += n - counts[i][0];
      }
      else if( counts[i][1] >= counts[i][0] and counts[i][1] >= counts[i][2] and counts[i][1] >= counts[i][3] ){
	cout << 'C';
	consensus_error += n - counts[i][1];
      }
      else if( counts[i][2] >= counts[i][0] and counts[i][2] >= counts[i][1] and counts[i][2] >= counts[i][3] ){
	cout << 'G';
	consensus_error += n - counts[i][2];
      }
      else if( counts[i][3] >= counts[i][0] and counts[i][3] >= counts[i][1] and counts[i][3] >= counts[i][2] ){
	cout << 'T';
	consensus_error += n - counts[i][3];
      }
    }
    cout << '\n' << consensus_error << '\n';
  }
  return 0;
}
