// UVa 11078 - Open Credit System

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int n {};
    cin >> n;
    int max_val {}, tmp {}, max_diff {-1000000};
    cin >> max_val;
    while( -- n ){
      cin >> tmp;
      if( max_val - tmp > max_diff ) max_diff = max_val - tmp;
      if( tmp > max_val ) max_val = tmp;
    }
    cout << max_diff << '\n';
  }
  return 0;
}
