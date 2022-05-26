#include <iostream>
#include <vector>

using namespace std;
constexpr int MAXN = 15;

int n {}, last_idx {};
int values[MAXN] {};
vector<int> combs;

void combinations( int offset, int k ){
  if( k == 0 ){
    for( int i = 0; i < (int)combs.size(); ++ i )
      cout << combs[i] << (i + 1 == (int)combs.size() ? "\n" : " ");
    return;
  }
  for( int i = offset; i <= n - k; ++ i ){
    combs.emplace_back( values[i] );
    combinations( i + 1, k - 1 );
    combs.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while( n ){
    for( int i = 0; i < n; ++ i )
      cin >> values[i];
    combinations( 0, 6 );
    cin >> n;
    if( n ) cout << '\n';
  }
  return 0;
}
