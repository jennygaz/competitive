#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<unsigned long long> values;
  for( int i = 0; i < 32; ++ i ){
    unsigned long long it = (1ULL << i);
    unsigned long long p3 = 1;
    for( int j = 0; it * p3 <= (1ULL << 31); ++ j ){
      values.emplace_back( it * p3 );
      p3 *= 3ULL;
    }
    if( it * p3 <= (1ULL << 30) )
      values.emplace_back( it * p3 );
  }
  sort( values.begin(), values.end() );
  unsigned long long n {};
  while( cin >> n, n ){
    cout << *lower_bound( values.begin(), values.end(), n ) << '\n';
  }
  return 0;
}
