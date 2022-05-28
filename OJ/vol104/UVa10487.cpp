#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> vals[MAXN] {};
  int n {}, CASE {1};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      cin >> vals[i];
    sort( vals.begin(), vals.begin() + n );
    int key {}, queries {};
    cin >> queries;
    cout << "Case " << CASE ++ << ":\n";
    while( queries -- ){
      cin >> key;
      int best = MAXN, sum {};
      cout << "The closest sum to " << key << " is ";
      for( int i = 0; i < n; ++ i ){
	auto lhs = lower_bound( vals.begin(), vals.begin() + n, key - vals[i] );
	auto rhs = (lhs == vals.begin() ? vals.begin() + n : lhs -- );
        if( lhs == vals.begin() ){
	  int tmp = vals[i] + *lhs;
	  if( tmp + *lhs < best ){
	    
	  }
	}
	else{
	  
	  best = min( best, min( vals[i] + *lhs, vals[i] + *rhs ) );
	}
	if( best == 0 ) break;
      }
      cout << 
    }
  }
  return 0;
}
