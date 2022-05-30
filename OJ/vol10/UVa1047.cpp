#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, target {}, ters {}, CASE {};
  int zones[20] {};
  int inters[20] {};
  int vals[20] {};
  while( cin >> n >> target, n | target ){
    for( int i = 0; i < n; ++ i )
      cin >> zones[i];
    cin >> ters;
    for( int i = 0; i < ters; ++ i ){
      int bits {}, mask {}, tmp {};
      cin >> bits;
      for( int j = 0; j < bits; ++ j ){
	cin >> tmp;
	mask |= (1 << (tmp - 1));
      }
      inters[i] = mask;
      cin >> vals[i];
    }
    int best_val {}, best_mask {};
    for( int mask = 0; mask < (1 << n); ++ mask ){
      if( __builtin_popcount( mask ) != target ) continue;
      int curr_val {};
      // add the intrinsic value of each zone
      for( int i = 0; i < n; ++ i )
	if( mask & (1 << i) )
	  curr_val += zones[i];
      // add the value of each intersection
      for( int i = 0; i < ters; ++ i ){
	int inter_mask = inters[i] & mask;
	if( inter_mask > 1 )
	  curr_val -= (__builtin_popcount(inter_mask) - 1) * vals[i];
      }
      if( curr_val > best_val ){
	best_val = curr_val;
	best_mask = mask;
      }
    }
    cout << "Case Number  " << ++CASE << '\n';
    cout << "Number of Customers: " << best_val << '\n';
    cout << "Locations recommended:";
    for( int i = 0; i < n; ++ i )
      if( best_mask & (1 << i) )
	cout << " " << (i + 1);
    cout << "\n\n";
  }
  return 0;
}
