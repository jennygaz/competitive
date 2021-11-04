#include <iostream>
#include <string>
#include <vector>

constexpr int MAX_LINES = 5;

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  vector<string> lines( MAX_LINES );
  getline( cin, lines[0] );
  n = stoi( lines[0] );
  for( int i {}; i < MAX_LINES; ++ i )
    getline( cin, lines[i] );
  for( int i = 0; i < n; ++ i ){
    if( lines[1][4 * i + 1] == '*' )
      cout << '1';
    else if( lines[3][4 * i] == '*' )
      cout << '2';
    else if( lines[3][4 * i + 2] == '*' )
      cout << '3';
  }
  cout << '\n';
  return 0;
}
