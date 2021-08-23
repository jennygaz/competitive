// UVa 11799 - Horror Dash

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE {1}; CASE <= tc; ++ CASE ){
    int n {}, max_val {}, tmp {};
    cin >> n;
    while( n -- ){
      cin >> tmp;
      if( tmp > max_val ) max_val = tmp;
    }
    cout << "Case " << CASE << ": " << max_val << '\n';
  }
  return 0;
}
