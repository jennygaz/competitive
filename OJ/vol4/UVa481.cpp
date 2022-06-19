#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
constexpr int MAXN = 1000100;

vector<int> values( MAXN ), parents( MAXN, -1 ), L( MAXN, 0 ), L_id( MAXN, -1 );

void printLIS( int idx ){
  if( parents[idx] == -1 ){
    cout << values[idx];
    return;
  }
  printLIS( parents[idx] );
  cout << '\n' << values[idx];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k {}, lis_end {};
  int val {}, val_idx {};
  while( cin >> val ){
    values[val_idx ++] = val;
  }
  for( int i = 0; i < val_idx; ++ i ){
    int pos = lower_bound( L.begin(), L.begin() + k, values[i] ) - L.begin();
    L[pos] = values[i];
    L_id[pos] = i;
    parents[i] = (pos ? L_id[pos - 1] : -1);
    if( pos == k ){
      k = pos + 1;
      lis_end = i;
    }
  }
  cout << k << "\n-\n";
  printLIS( lis_end );
  cout << '\n';
  return 0;
}
