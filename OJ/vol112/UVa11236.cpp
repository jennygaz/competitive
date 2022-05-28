#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int million = 1000000;
  for( int a = 1; a <= 500; ++ a ){
    for( int b = a; a + b * 3 <= 2000; ++ b ){
      for( int c = b; a + b + c * 2 <= 2000; ++ c ){
	int product = a * b * c;
	int sum = a + b + c;
	if( product <= million ) continue;
	int d = million * sum / (product - million);
	if( d < c or sum + d > 2000 ) continue;
	if( fabs( (sum + d) / 100.0 - (product * d) / 100000000.0 ) < 1e-9 )
	  cout << a / 100 << "." << setw(2) << setfill('0') << a % 100 << " "
	       << b / 100 << "." << setw(2) << setfill('0') << b % 100 << " "
	       << c / 100 << "." << setw(2) << setfill('0') << c % 100 << " "
	       << d / 100 << "." << setw(2) << setfill('0') << d % 100 << '\n';
      }
    }
  }
  return 0;
}
