#include <iostream>
#include <tuple>
#include <functional>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for( int a = 1; a <= 200; ++ a ){
    int a_cube = a * a * a;
    for( int b = 2; b <= 200; ++ b ){
      int b_cube = b * b * b;
      if( b_cube >= a_cube ) break;
      for( int c = b; c <= 200; ++ c ){
	int c_cube = c * c * c;
	if( c_cube + b_cube >= a_cube ) break;
	for( int d = c; d <= 200; ++ d ){
	  int d_cube = d * d * d;
	  if( d_cube + c_cube + b_cube > a_cube ) break;
	  if( d_cube + c_cube + b_cube == a_cube )
	    cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
	}
      }
    }
  }
  return 0;
}
