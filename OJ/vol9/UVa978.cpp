/* UVa 978 - Lemmings Battle! */
/* Solution: Use a priority queue */
/* by jennyga */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAXBF = 100100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int lhs_bf[MAXBF] {}, rhs_bf[MAXBF] {};
  cin >> tc;
  while( tc -- ){
    int battlefields {}, lhs {}, rhs {};
    cin >> battlefields >> lhs >> rhs;
    priority_queue<int> lhs_pq {}, rhs_pq {};
    for( int i = 0; i < lhs; ++ i ){
      int tmp {};
      cin >> tmp;
      lhs_pq.emplace( tmp );
    }
    for( int i = 0; i < rhs; ++ i ){
      int tmp {};
      cin >> tmp;
      rhs_pq.emplace( tmp );
    }
    while( not lhs_pq.empty() and not rhs_pq.empty() ){
      int min_val = min( (long unsigned) battlefields, min( lhs_pq.size(), rhs_pq.size() ) );
      for( int i = 0; i < min_val; ++ i ){
	lhs_bf[i] = lhs_pq.top();
	lhs_pq.pop();
	rhs_bf[i] = rhs_pq.top();
	rhs_pq.pop();
      }
      for( int i = 0; i < min_val; ++ i ){
	int res = lhs_bf[i] - rhs_bf[i];
	if( res < 0 )
	  rhs_pq.emplace( -res );
	else if( res > 0 )
	  lhs_pq.emplace( res );
      }
    } // end while
    if( lhs_pq.empty() and rhs_pq.empty() )
      cout << "green and blue died\n";
    else if( lhs_pq.empty() ){
      cout << "blue wins\n";
      while( not rhs_pq.empty() ){
	cout << rhs_pq.top() << '\n';
	rhs_pq.pop();
      }
    }
    else if( rhs_pq.empty() ){
      cout << "green wins\n";
      while( not lhs_pq.empty() ){
	cout << lhs_pq.top() << '\n';
	lhs_pq.pop();
      }
    }
    if( tc ) cout << '\n';
  }
  return 0;
}
