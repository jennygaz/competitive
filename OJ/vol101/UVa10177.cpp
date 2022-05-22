#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unsigned long long memo[101][6] {};
  for( unsigned long long i = 1; i <= 100; ++ i ){
    unsigned long long base = i * (i + 1) / 2;
    unsigned long long& s2 = memo[i][0];
    unsigned long long& r2 = memo[i][1];
    unsigned long long& s3 = memo[i][2];
    unsigned long long& r3 = memo[i][3];
    unsigned long long& s4 = memo[i][4];
    unsigned long long& r4 = memo[i][5];
    s2 = base * ((i << 1) + 1) / 3;
    s3 = base * base;
    s4 = s2 * (3 * (i * (i + 1)) - 1) / 5;
    r2 = s3 - s2;
    r3 = s3 * (base - 1);
    r4 = s3 * s3 - s4;
  }
  int n {};
  while( cin >> n ){
    for( int i = 0; i < 6; ++ i )
      cout << memo[n][i] << (i + 1 == 6 ? "\n" : " ");
  }
  return 0;
}
