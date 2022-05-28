#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  while( tc -- ){
    int A {}, B {}, C {};
    cin >> A >> B >> C;
    bool done {};
    for( int x = -22; x <= 22 and not done; ++ x ){
      if( x * x <= C ){
	for( int y = -100; y <= 100 and not done; ++ y ){
	  if( y != x and x * x + y * y <= C ){
	    for( int z = -100; z <= 100 and not done; ++ z ){
	      if( z != x and z != y and x + y + z == A and x * y * z == B
		  and x * x + y * y + z * z == C ){
		cout << x << " " << y << " " << z << '\n';
		done = true;
	      } } } } } }
    if( not done ) cout << "No solution.\n";
  }
  return 0;
}
