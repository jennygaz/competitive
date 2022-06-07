#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

struct Chamber {
  int specs[2];
  int idxs[2];
  int total;
  Chamber( int spec1_, int idx1_, int spec2_, int idx2_ ){
    if( spec1_ == 0 and spec2_ == 0 )
      total = 0;
    else if( spec1_ == 0 ){
      specs[0] = spec2_;
      idxs[0] = idx2_;
      total = 1;
    }
    else if( spec2_ == 0 ){
      specs[0] = spec1_;
      idxs[0] = idx1_;
      total = 1;
    }
    else{
      total = 2;
      if( idx1_ < idx2_ ){
	idxs[0] = idx1_;
	idxs[1] = idx2_;
	specs[0] = spec1_;
	specs[1] = spec2_;
      }
      else{
	idxs[1] = idx1_;
	idxs[0] = idx2_;
	specs[1] = spec1_;
	specs[0] = spec2_;
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int c {}, s {}, CASE {};
  while( cin >> c >> s ){
    double avg = 0, sum = 0;
    vector<int> chambers( c, 0 );
    vector<tuple<int, int>> specimens( 2 * c, {0, 0} );
    for( int i = 0; i < s; ++ i ){
      int weight {};
      cin >> weight;
      specimens[i] = { weight, i };
      avg += weight;
    }
    avg /= c;
    sort( specimens.begin(), specimens.end(),
	  []( tuple<int, int>& lhs, tuple<int, int>& rhs ) -> bool {
	    return get<0>( lhs ) < get<0>( rhs );
    });
    vector<Chamber> sorted;
    for( int i = 0; i < c; ++ i ){
      auto& a = specimens[i], b = specimens[2 * c - i - 1];
      double weight = get<0>( a ) + get<0>( b );
      sorted.emplace_back( get<0>( a ), get<1>( a ), get<0>( b ), get<1>( b ) );
      sum += abs( weight - avg );
    }
    sort( sorted.begin(), sorted.end(),
	  []( const Chamber& lhs, const Chamber& rhs ) -> bool {
	    if( lhs.total == 2 and rhs.total == 2 )
	      return lhs.idxs[0] < rhs.idxs[0];
	    else if( lhs.total == 1 and rhs.total == 1 )
	      return lhs.idxs[0] < rhs.idxs[0];
	    else if( lhs.total == 1 and rhs.total == 2 )
	      return lhs.idxs[0] < rhs.idxs[0];
	    else if( lhs.total == 2 and rhs.total == 1 )
	      return lhs.idxs[0] < rhs.idxs[0];
	    else
	      return false;
	  });
    cout << "Set #" << ++CASE << "\n";
    for( int i = 0; i < c; ++ i ){
      cout << " " << i << ":";
      if( sorted[i].total == 1 )
	cout << " " << sorted[i].specs[0] << '\n';
      else if( sorted[i].total == 2 )
	cout << " " << sorted[i].specs[0] << " " << sorted[i].specs[1] << '\n';
      else
	cout << '\n';
    }
    cout << "IMBALANCE = " << setprecision( 5 ) << fixed << sum << "\n\n";
  }
  return 0;
}
