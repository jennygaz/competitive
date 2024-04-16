/* UVa 10107 - What is the Median? */
/* by @jennygaz */
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// to check easily which side has less values
enum Balance { LHS = -1, MID = 0, RHS = 1 };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  priority_queue<int> max_heap {};
  priority_queue<int, vector<int>, greater<int>> min_heap {};
  int value {};
  long median {};
  cin >> value;
  median = value;
  cout << median << '\n';
  max_heap.emplace( value );
  while( cin >> value ) {
    Balance result;
    if( max_heap.size() < min_heap.size() ) result = Balance::LHS;
    else if( max_heap.size() > min_heap.size() ) result = Balance::RHS;
    else result = Balance::MID;
    switch (result) {
    case Balance::LHS:
      if( value > median ) {
	max_heap.push( min_heap.top() );
	min_heap.pop();
	min_heap.push( value );
      } else max_heap.push( value );
      median = (min_heap.top() + max_heap.top());
      median >>= 1;
      break;
    case Balance::RHS:
      if( value < median ) {
	min_heap.push( max_heap.top() );
	max_heap.pop();
	max_heap.push( value );
      } else min_heap.push( value );
      median = (min_heap.top() + max_heap.top());
      median >>= 1;
      break;
    case Balance::MID:
      if( value < median ) {
	max_heap.push( value );
	median = max_heap.top();
      } else {
	min_heap.push( value );
	median = min_heap.top();
      }
    }
    cout << median << '\n';
  }
  return 0;
}
