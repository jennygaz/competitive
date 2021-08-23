// UVa 12372 - Packing for Holiday

#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  constexpr int MAX_DIM {20};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int L {}, W {}, H {};
    cin >> L >> W >> H;
    cout << "Case " << CASE << ": "
	 << (L <= MAX_DIM and W <= MAX_DIM and H <= MAX_DIM
	     ? "good\n" : "bad\n");
  }
  return 0;
}
