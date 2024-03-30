#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  string line(100, '0');
  cin >> n;
  while( n -- ){
    int ans {}, running_sum {};
    cin >> line;
    for( auto c : line ){
      if( c == 'O' ){
        ++ running_sum;
        ans += running_sum;
      }
      else if( c == 'X' )
        running_sum = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
