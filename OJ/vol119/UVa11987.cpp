#include <iostream>
#include <algorithm>

using namespace std;

/* UFDS data structure for personal use */
/* by jennyga */

constexpr int MAXSIZE = 1000001;
int pa[MAXSIZE], set_sum[MAXSIZE], set_size[MAXSIZE];
int num_sets = MAXSIZE;
int max_sets = MAXSIZE;
int start_idx = 0;

inline void init( int n, int idx = 0 ){
  num_sets = n + idx;
  max_sets = n + idx;
  start_idx = idx;
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i;
    set_sum[i] = set_size[i] = 1;
  }
}

inline int find_set( int i ){
  return pa[i] == i ? i : pa[i] = find_set( pa[i] );
}

inline bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

inline int size_of_set( int i ){
  return set_size[find_set( i )];
}

inline int sum_of_set( int i ){
  return set_sum[find_set( i )];
}

inline bool union_set( int i, int j ){
  if( is_same_set( i, j ) ) return false;
  -- num_sets;
  int x = find_set( i ), y = find_set( j );
  if( size_of_set( x ) >= size_of_set( y ) )
    swap( x, y );
  set_sum[y] += set_sum[x];
  pa[x] = y;
  set_sum[x] = x;
  set_size[x] += set_size[y];
  return true;
}

inline bool splice_set( int elem, int id_set ){
  int pa_set = find_set( id_set );
  int pa_elem = find_set( elem );
  for( int i = start_idx; i < max_sets; ++ i )
    if( pa[i] == elem )
      pa[i] = pa_set;
  pa[elem] = elem;
  set_size[pa_elem] --;
  set_size[elem] = 1;
  set_sum[pa_elem] -= elem;
  set_sum[elem] = elem;
  return union_set( elem, id_set );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, m {};
  while( cin >> n >> m ){
    init( n, 1 );
    int q {}, a {}, b {};
    while( m -- ){
      cin >> q >> a;
      if( q == 1 ){
	cin >> b;
	union_set( a, b );
      }
      else if( q == 2 ){
	cin >> b;
	splice_set( a, b );
      }
      else if( q == 3 ){
	cout << size_of_set( a ) << " " << sum_of_set( a ) << '\n';
      }
    }
  }
  return 0;
}
