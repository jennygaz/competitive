// UVa 11044: Searching for Nessy

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int m {}, n {};
    cin >> m >> n;
    cout << (m / 3) * (n / 3) << '\n';
  }
  return 0;
}
