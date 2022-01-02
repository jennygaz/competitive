/* UVa 11581 - Grid Successors */
/* Solution: hash all solutions and pre-compute them */
/* by jennyga */

#include <iostream>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

constexpr int MAXBITS = 9;

int transformation( string str ){
  int iters {-1};
  while( str != "000000000" ){
    for( size_t i = 0; i < str.length(); ++ i )
      str[i] -= '0';
    string ans = str;
    ans[0] = (str[1] + str[3]) % 2;
    ans[1] = (str[0] + str[2] + str[4]) % 2;
    ans[2] = (str[1] + str[5]) % 2;
    ans[3] = (str[0] + str[4] + str[6]) % 2;
    ans[4] = (str[1] + str[3] + str[5] + str[7]) % 2;
    ans[5] = (str[2] + str[4] + str[8]) % 2;
    ans[6] = (str[3] + str[7]) % 2;
    ans[7] = (str[4] + str[6] + str[8]) % 2;
    ans[8] = (str[5] + str[7]) % 2;
    for( size_t i = 0; i < str.length(); ++ i )
      str[i] = ans[i] + '0';
    ++ iters;
  }
  return iters;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_map<string, int> answers {};
  for( int i = 0; i < (1 << 10); ++ i ){
    bitset<MAXBITS> tmp( i );
    string str = tmp.to_string();
    answers[str] = transformation( str );
  }
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    getline( cin, line );
    string key {};
    for( int i = 0; i < 3; ++ i ){
      getline( cin, line );
      key += line;
    }
    cout << answers[key] << '\n';
  }
  return 0;
}
