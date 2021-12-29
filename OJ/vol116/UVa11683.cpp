/* UVa 11683 - Laser Sculpture */
/* Solution: check the local differences */
/* by jennyga */
 
#include <iostream>

using namespace std;
constexpr int MAXN = 10010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int height {}, width {};
  int vals[MAXN] {};
  while( cin >> height, height != 0 ){
    cin >> width;
    cin >> vals[0];
    int i {}, cost = height - vals[0];
    for( i = 1; i < width; ++ i ){
      cin >> vals[i];
      if( vals[i] != height and vals[i - 1] - vals[i] > 0 )
	cost += vals[i - 1] - vals[i];
    }
    cout << cost << '\n';
  }
  return 0;
}
