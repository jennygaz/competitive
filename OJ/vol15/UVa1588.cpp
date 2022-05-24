#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
constexpr int MAXN = 500;

inline bool check( int index, string& lhs, string& rhs ){
  int i = index, j = 0;
  while( i < (int)lhs.size() and j < (int)rhs.size() ){
    if( lhs[i] == '2' and rhs[j] == '2' )
      return false;
    ++ i;
    ++ j;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string lhs {}, rhs {};
  while( cin >> lhs >> rhs ){
    int lhs_idx {}, rhs_idx {};
    while( lhs_idx < (int)lhs.size() ){
      if( check( lhs_idx, lhs, rhs ) ) break;
      ++ lhs_idx;
    }
    while( rhs_idx < (int)rhs.size() ){
      if( check( rhs_idx, rhs, lhs ) ) break;
      ++ rhs_idx;
    }
    cout << min( max( rhs.size() + lhs_idx, lhs.size() ),
		 max( lhs.size() + rhs_idx, rhs.size() ) ) << '\n';
  }
  return 0;
}
