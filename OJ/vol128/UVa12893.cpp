#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<unsigned long long, unsigned long long> num;

unsigned long long ans( unsigned long long n ){
  if( n == 0ULL ) return 0ULL;
  if( num[n] != 0 ) return num[n];
  return num[n] = ans(n/2) + (n % 2);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    unsigned long long n {};
    cin >> n;
    cout << ans( n ) << '\n';
  }
  return 0;
}
