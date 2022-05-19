#include <bits/stdc++.h>
using namespace std;

int row[8], a, b, lineCounter;
vector<vector<int>> solutions;

bool canPlace(int r, int c) {
  for (int prev = 0; prev < c; ++prev)
    if ((row[prev] == r) || (abs(row[prev]-r) == abs(prev-c)))
      return false;
  return true;
}

void backtrack(int c) {
  if ((c == 8) && (row[b] == a)) {
    vector<int> vals( row, row + 8 );
    solutions.emplace_back( vals.begin(), vals.end() );
    return;
  }
  for (int r = 0; r < 8; ++r) {
    if ((c == b) && (r != a)) continue;
    if (canPlace(r, c))
      row[c] = r, backtrack(c+1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solutions.reserve( 1000 );
  for( a = 0; a < 8; ++ a )
    for( b = 0; b < 8; ++ b ){
      memset(row, 0, sizeof row);
      backtrack(0);
    }
  int tc {};
  cin >> tc;
  int grid[8][8] {};
  while( tc -- ){
    long long score {};
    for( int i = 0; i < 8; ++ i )
      for( int j = 0; j < 8; ++ j )
	cin >> grid[i][j];
    for( auto& sol : solutions ){
      long long tmp {};
      for( int x = 0; x < (int)sol.size(); ++ x )
	tmp += grid[x][sol[x]];
      score = max( score, tmp );
    }
    cout << setw( 5 ) << std::right << score << '\n';
  }
  return 0;
}
