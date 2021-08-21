// UVa 10071 - Back to High School Physics

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int v {}, t {};
  while( cin >> v >> t ){
    cout << v * t * 2 << '\n';
  }
  return 0;
}
