#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  cout << "PERFECTION OUTPUT\n";
  while( cin >> n, n ){
    int sum {};
    for( int i = 1; i < n; ++ i )
      if( n % i == 0 )
	sum += i;
    cout << setw( 5 ) << n;
    if( n == sum )
      cout << "  PERFECT\n";
    else if( n < sum )
      cout << "  ABUNDANT\n";
    else
      cout << "  DEFICIENT\n";
  }
  cout << "END OF OUTPUT\n";
  return 0;
}
