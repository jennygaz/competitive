// UVa12279 - Emoogle Balance

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, CASE {1};
  while( cin >> n, n ){
    int reasons {}, gifts {}, tmp {};
    while( n -- ){
      cin >> tmp;
      if( tmp ) ++ reasons;
      else ++ gifts;
    }
    cout << "Case " << CASE ++ << ": " << reasons - gifts << '\n';
  }
  return 0;
}
