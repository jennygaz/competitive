#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;
/* UFDS data structure for personal use */
/* by jennyga */

constexpr int MAXSIZE = 20020;
int pa[MAXSIZE];
int num_sets = MAXSIZE;

inline void show_sets( int n, int idx = 0 ){
  for( int i = idx; i < num_sets; ++ i )
    cout << "pa[" << i << "] = " << pa[i] << '\n';
}

inline void init( int n, int idx = 0 ){
  num_sets = n + idx;
  for( int i = idx; i < num_sets; ++ i )
    pa[i] = i;
}

inline int find_set( int i ){
  return pa[i] == i ? 0 : pa[i] = abs( (pa[i] - i) % 1000 ) + find_set( pa[i] );
  if( pa[i] == i ) return 0;
  else
    return abs( (pa[i] - i) ) % 1000 + find_set( pa[i] );
}

inline bool union_set( int i, int j ){
  pa[i] = j;
  return true;
}

// inline bool union_set( int i, int j ){
//   if( is_same_set( i, j ) ) return false;
//   -- num_sets;
//   int x = find_set( i ), y = find_set( j );
//   if( ra[x] > ra[y] ){
//     pa[y] = x;
//     set_size[x] += set_size[y];
//   }
//   else{
//     pa[x] = y;
//     set_size[y] += set_size[x];
//     if( ra[x] == ra[y] ) ra[y] ++;
//   }
//   return true;
// }

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {}, a {}, b {}, n {};
  string line {};
  char qt {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    getline( cin, line );
    n = stoi( line );
    init( n, 1 );
    while( getline( cin, line ) ){
      istringstream iss( line );
      iss >> qt;
      if( qt == 'E' ){
	iss >> a;
	cout << find_set( a ) << '\n';
      }
      else if( qt == 'I' ){
	iss >> a >> b;
	union_set( a, b );
      }
      else break;
    }
  }
  return 0;
}
