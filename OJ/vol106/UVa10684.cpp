#include <iostream>

using namespace std;
constexpr int MAXN = 10100;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int values[MAXN] {};
  while( cin >> n, n ){
    int best_sum {-100000000}, curr_sum {};
    for( int i = 0; i < n; ++ i ){
      cin >> values[i];
      curr_sum += values[i];
      best_sum = max( best_sum, curr_sum );
      if( curr_sum < 0 )
	curr_sum = 0;
    }
    if( best_sum <= 0 )
      cout << "Losing streak.\n";
    else
      cout << "The maximum winning streak is " << best_sum << ".\n";
  }
  return 0;
}
