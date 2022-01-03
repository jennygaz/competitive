/* UVa 10107 - What is the Median? */
/* Solution: Use two priority queues to get the median easily, or sort after every insertion */
/* by jennyga */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  priority_queue<int> lhs {};
  priority_queue<int, vector<int>, greater<int>> rhs {};
  while( cin >> n ){
    if( lhs.size() == rhs.size() ){
      if( lhs.empty() ) // base case
	lhs.push( n );
      else{
	if( lhs.top() > n ){
	  rhs.push( lhs.top() );
	  lhs.pop();
	  lhs.push( n );
	}
	else
	  rhs.push( n );
      }
    } // end if equal size
    else if( lhs.size() < rhs.size() ){
      if( rhs.top() < n ){
	lhs.push( rhs.top() );
	rhs.pop();
	rhs.push( n );
      }
      else
	lhs.push( n );
    } // end if lhs < rhs
    else{
      if( lhs.top() > n ){
	rhs.push( lhs.top() );
	lhs.pop();
	lhs.push( n );
      }
      else
	rhs.push( n );
    }
    // compute the median
    if( (lhs.size() + rhs.size()) % 2 == 0 )
      cout << (lhs.top() + rhs.top())/2 << '\n';
    else if( lhs.size() > rhs.size() )
      cout << lhs.top() << '\n';
    else
      cout << rhs.top() << '\n';
  }
  return 0;
}
