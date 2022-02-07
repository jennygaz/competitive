/* UVa 599 - The Forest of the Trees */
/* Solution: Parsing is the hardest part, just run a dfs or similar to check the connected components in the graph, or a UFDS */
/* by jennyga */

#include <string>
#include <iostream>
#include <sstream>

using namespace std;
constexpr int MAX_VERTICES = 26;
constexpr int MAX_EDGES = MAX_VERTICES * MAX_VERTICES;

int pa[MAX_VERTICES] {}, ra[MAX_VERTICES] {}, set_size[MAX_VERTICES] {};
int num_sets = MAX_VERTICES;

inline void init( int n, int idx = 0 ){
  num_sets = n + idx;
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i;
    ra[i] = set_size[i] = 1;
  }
}

inline int find_set( int i ){
  return pa[i] == i ? i : pa[i] = find_set( pa[i] );
}

inline bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

inline bool union_set( int i, int j ){
  if( is_same_set( i, j ) ) return false;
  -- num_sets;
  int x = find_set( i ), y = find_set( j );
  if( ra[x] > ra[y] ){
    pa[y] = x;
    set_size[x] += set_size[y];
  }
  else{
    pa[x] = y;
    set_size[y] += set_size[x];
    if( ra[x] == ra[y] ) ra[y] ++;
  }
  return true;
}

inline int size_of_set( int i ){
  return set_size[find_set( i )];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string vertices {};
  string edges[MAX_EDGES] {};
  cin >> tc;
  while( tc -- ){
    int edge_idx {}, vertex_idx {};
    int keys[256] {}, used[MAX_VERTICES] {};
    while( cin >> edges[edge_idx], edges[edge_idx][0] != '*' )
      ++ edge_idx;
    cin >> vertices;
    for( int i = 0; i < (int)vertices.length(); i += 2 )
      keys[vertices[i]] = vertex_idx ++;
    init( vertex_idx );
    for( int i = 0; i < edge_idx; ++ i )
      union_set( keys[edges[i][1]], keys[edges[i][3]] );
    int trees {}, acorns {};
    for( int i = 0; i < vertex_idx; ++ i ){
      int rep = find_set( i );
      if( not used[rep] ){
	if( size_of_set( rep ) == 1 )
	  ++ acorns;
	else
	  ++ trees;
	used[rep] = 1;
      }
    }
    cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
  }
  return 0;
}
