#include <iostream>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, b {};
  
  while( cin >> n >> b, n > 0 and b > 0 ){
    int val {};
    priority_queue<tuple<double, int, int>> pq {};
    for( int i = 0; i < n; ++ i ){
      cin >> val;
      pq.emplace( val, val, 1 );
    }
    b -= n;
    while( b -- ){
      auto node = pq.top();
      int num = get<1>( node );
      int den = get<2>( node );
      pq.pop();
      pq.emplace( num / (den + 1.0), num, den + 1 );
    }
    auto worst = pq.top();
    cout << (int)(ceil( get<0>( worst ) )) << '\n';
  }
  return 0;
}
