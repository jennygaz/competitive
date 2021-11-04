#include <iostream>
#include <string>
#include <vector>

constexpr int MAXN = 110;
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> instructions( MAXN );
  string line {};  
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {}, pos {};
    cin >> n;
    for( int i {}; i < n; ++ i ){
      cin >> line;
      if( line[0] == 'S' ){
	cin >> line;
	int tmp {};
	cin >> tmp;
	instructions[i] = instructions[tmp - 1];
      }
      else
	instructions[i] = (line[0] == 'L' ? -1 : (line[0] == 'R' ? 1 : 0));
      pos += instructions[i];
    }
    cout << pos << '\n';
  }
  return 0;
}
