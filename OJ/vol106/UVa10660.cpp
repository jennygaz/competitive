#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using iii = tuple<int, int, int>;
constexpr int INF = 1e9 + 7, MATSIZE = 5, MAXELEM = 25;

int n {}, best_sum {INF}, best_mask{};
iii points[MAXELEM] {};

inline int d( ii lhs, ii rhs ){
  return abs( get<0>( lhs ) - get<0>( rhs ) ) + abs( get<1>( lhs ) - get<1>( rhs ) );
}

inline int d( ii lhs, iii rhs ){
  return abs( get<0>( lhs ) - get<1>( rhs ) ) + abs( get<1>( lhs ) - get<2>( rhs ) );
}

inline int d( int x1, int y1, int x2, int y2 ){
  return abs( x1 - x2 ) + abs( y1 - y2 );
}

void init(){
  for( int i {}; i < MAXELEM; ++ i )
    points[i] = { 0, i / 5, i % 5 };
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    cin >> n;
    init();
    best_sum = INF;
    best_mask = 0;
    for( int i = 0; i < n; ++ i ){
      int x {}, y {}, val {};
      cin >> x >> y >> val;
      points[i] = { val, x, y };
    }
    int s{};
    for( int A {}; A < MAXELEM; ++ A ){
      for( int B {A+1}; B < MAXELEM; ++ B ){
	for( int C{B+1}; C < MAXELEM; ++ C ){
	  for( int D{C+1}; D < MAXELEM; ++ D ){
	    for( int E{D+1}; E < MAXELEM; ++ E ){
	      ii offices[] = { { A / MATSIZE, A % MATSIZE },
 												{ B / MATSIZE, B % MATSIZE },
			       						 { C / MATSIZE, C % MATSIZE },
			       						 { D / MATSIZE, D % MATSIZE },
			       						 { E / MATSIZE, E % MATSIZE }
	      };
	      s = 0;
	      for( auto p : points ){
		iii a[MATSIZE] = { { d( offices[0], p ), get<0>( offices[0] ), get<1>( offices[0] ) },
				   { d( offices[1], p ), get<0>( offices[1] ), get<1>( offices[1] ) },
				   { d( offices[2], p ), get<0>( offices[2] ), get<1>( offices[2] ) },
				   { d( offices[3], p ), get<0>( offices[3] ), get<1>( offices[3] ) },
				   { d( offices[4], p ), get<0>( offices[4] ), get<1>( offices[4] ) },
		};
		sort( a, a + MATSIZE, []( iii& lhs, iii& rhs ) -> bool {
					if( get<0>( lhs ) != get<0>( rhs ) )
					  return get<0>( lhs ) < get<0>( rhs );
					else if( get<1>( lhs ) != get<1>( rhs ) )
					  return get<1>( lhs ) < get<1>( rhs );
					else
					  return get<2>( lhs ) < get<2>( rhs );
				      });
		s += get<0>( a[0] ) * get<0>( p );
	      }
	      if( s < best_sum ){
		best_mask = (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << E);
		best_sum = s;
	      }
	    }
	  }
	}
      }
    }
    int seen = 0;
    for( int i = 0; i < MAXELEM; ++ i )
      if( best_mask & (1 << i) ){
	++ seen;
	cout << i << (seen == 5 ? '\n' : ' ');
      }
  }
}
