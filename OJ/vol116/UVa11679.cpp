#include <iostream>
constexpr int MAXN = 22;
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int b {}, n {};
  while( cin >> b >> n, b | n ){
    int from_ {}, to_ {}, cost_ {};
    int reserves[MAXN] {};
    for( int i = 1; i <= b; ++ i )
      cin >> reserves[i];
    while( n -- ){
      cin >> from_ >> to_ >> cost_;
      reserves[from_] -= cost_;
      reserves[to_] += cost_;
    }
    bool bailout = false;
    for( int i = 1; not bailout and i <= b; ++ i )
      bailout = (reserves[i] < 0);
    if( bailout )
      cout << "N\n";
    else
      cout << "S\n";
  }
  return 0;
}
