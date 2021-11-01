#include <bits/stdc++.h>

constexpr int MAXN = 10;
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    vector<tuple<int, int, string>> values {};
    string website {};
    int web_rank {};
    for( int i = 0; i < MAXN; ++ i ){
      cin >> website >> web_rank;
      values.emplace_back( -web_rank, i, website );
    }
    sort( values.begin(), values.end() );
    cout << "Case #" << CASE << ":\n";
    for( int i = 0; i < MAXN; ++ i )
      if( get<0>( values[i] ) == get<0>( values[0] ) )
	cout << get<2>( values[i] ) << '\n';
  }
  return 0;
}
