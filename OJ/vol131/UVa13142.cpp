#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    long long T {}, S {}, D {};
    cin >> T >> S >> D;
    T *= 24LL * 60LL * 60LL;
    D *= 1000000LL;
    double vel = floor( D / T );
    if( vel > 0 )
      cout << "Remove " << (int)(vel) << " tons\n";
    else
      cout << "Add " << (int)(abs(vel)) << " tons\n";
  }
  return 0;
}
