#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
constexpr int MAXN = 10;
constexpr double INF = 2e9;

int N {};
int x[MAXN] {}, y[MAXN] {};
double dist[MAXN][MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASE {1};
  while( cin >> N, N ){
    int perms[MAXN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int best_perm[MAXN] {};
    double min_dist = INF;
    string asterisks = "**********************************************************\n";
    for( int i = 0; i < N; ++ i )
      cin >> x[i] >> y[i];
    for( int i = 0; i < N; ++ i )
      for( int j = i + 1; j < N; ++ j )
	dist[i][j] = dist[j][i] = 16 + hypot( x[i] - x[j], y[i] - y[j] );
    do{
      double curr_dist {};
      for( int i = 0; i < N - 1; ++ i )
	curr_dist += dist[perms[i]][perms[i + 1]];
      if( curr_dist < min_dist ){
	for( int i = 0; i < N; ++ i )
	  best_perm[i] = perms[i];
	min_dist = curr_dist;
      }
    } while( next_permutation( perms, perms + N ) );
    cout << asterisks << "Network #" << CASE++ << '\n';
    for( int i = 0; i < N - 1; ++ i ){
      int from[2] = { x[best_perm[i]], y[best_perm[i]] },
	to[2] = { x[best_perm[i + 1]], y[best_perm[i + 1]] };
      cout << "Cable requirement to connect (" << from[0] << "," << from[1]
	   << ") to (" << to[0] << "," << to[1] << ") is "
	   << setprecision( 2 ) << fixed << dist[best_perm[i]][best_perm[i + 1]]
	   << " feet.\n";
    }
    cout << "Number of feet of cable required is " << min_dist << ".\n";
  }
  return 0;
}
