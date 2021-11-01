#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000100;

int down_to_zero( int n ){
  int memo[MAXN] {};
  queue<int> q {};
  q.emplace( n );
  while( not q.empty() ){
    int tmp = q.front();
    q.pop();
    if( tmp == 0 ) break;
    if( memo[tmp - 1] == 0 ){
      q.push( tmp - 1 );
      memo[tmp - 1] = memo[tmp] + 1;
    }
    for( int i = sqrt(tmp); i >= 2; -- i ){
      if( tmp % i == 0 and memo[tmp / i] == 0 ){
	q.push( tmp / i );
	memo[tmp / i] = memo[tmp] + 1;
      }
    }
  }
  return memo[0];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q {}, n {};
  cin >> q;
  while( q -- ){
    cin >> n;
    cout << down_to_zero( n ) << '\n';
  }
  return 0;
}
