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
  while( cin >> n, n ){
    int val {};
    priority_queue<int, vector<int>, greater<int>> pq {};
    while( n -- ){
      cin >> val;
      pq.emplace( val );
    }
    int cost {};
    while( pq.size() > 1 ){
      int lhs = pq.top();
      pq.pop();
      int rhs = pq.top();
      pq.pop();
      cost += lhs + rhs;
      pq.emplace( lhs + rhs );
    }
    cout << cost << '\n';
  }
  return 0;
}
