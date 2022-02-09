/* UFDS data structure for personal use */
/* by jennyga */

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
