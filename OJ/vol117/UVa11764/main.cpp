// UVa 11764 - Jumping Mario

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE {1}; CASE <= tc; ++ CASE ){
    int n {}, prev {}, curr {}, low {}, tall {};
    cin >> n;
    cin >> prev;
    while( -- n ){
      cin >> curr;
      if( prev < curr ) ++ tall;
      else if( prev > curr ) ++ low;
      prev = curr;
    }
    cout << "Case " << CASE << ": " << tall << " " << low << '\n';
  }
  return 0;
}
