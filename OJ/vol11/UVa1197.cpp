/* UVa 1197 - The Suspects */
/* Solution: Use Union Find Disjoint Sets to find the suspects */
/* by jennyga */

/* UFDS data structure for personal use */
/* by jennyga */

#include <iostream>

using namespace std;

constexpr int MAXSIZE = 1000001;
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE];
int num_sets = MAXSIZE;

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
  int n {}, m {};
  while( cin >> n >> m, n | m ){
    init( n );
    for( int i = 0; i < m; ++ i ){
      int k {}, tmp {}, prev {};
      cin >> k;
      for( int j = 0; j < k; ++ j ){
	if( j ){
	  cin >> tmp;
	  union_set( prev, tmp );
	}
	else
	  cin >> prev;
      }
    }
    cout << size_of_set( 0 ) << '\n';
  }
  return 0;
}
