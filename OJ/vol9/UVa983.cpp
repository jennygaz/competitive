#include <iostream>

using namespace std;
constexpr int MAXN = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {};
  int values[MAXN][MAXN] {};
  bool first = true;
  while( cin >> n >> m ){
    if( not first ) cout << '\n';
    first = false;
    for( int i = 0; i < n; ++ i ){
      for( int j = 0; j < n; ++ j ){
	cin >> values[i][j];
	if( i > 0 ) values[i][j] += values[i - 1][j];
	if( j > 0 ) values[i][j] += values[i][j - 1];
	if( i > 0 and j > 0 ) values[i][j] -= values[i - 1][j - 1];
      }
    }
    int total {};
    for( int i = m - 1; i < n; ++ i ){
      for( int j = m - 1; j < n; ++ j ){
	int curr_val = values[i][j];
	if( i >= m ) curr_val -= values[i - m][j];
	if( j >= m ) curr_val -= values[i][j - m];
	if( i >= m and j >= m ) curr_val += values[i - m][j - m];
	cout << curr_val << '\n';
	total += curr_val;
      }
    }
    cout << total << '\n';
  }
  return 0;
}
