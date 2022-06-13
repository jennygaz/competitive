#include <iostream>

using namespace std;
constexpr int MAXN = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int vals[MAXN] {};
  while( cin >> n, n ){
    int max_arr[MAXN] {}, idx {};
    for( int i = 0; i < n; ++ i ){
      cin >> vals[i];
      if( vals[i] > 0 )
	max_arr[idx ++] = vals[i];
    }
    if( idx == 0 ) cout << "0\n";
    else{
      for( int i = 0; i < idx; ++ i )
	cout << max_arr[i] << (i + 1 == idx ? "\n" : " ");
    }
  }
  return 0;
}
