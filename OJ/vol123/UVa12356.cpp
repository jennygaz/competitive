#include <iostream>

using namespace std;

constexpr int MAXN = 100100;
int L[MAXN] {}, R[MAXN] {};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int B {}, S {};
  while( cin >> S >> B, S | B ){
    for( int i = 1; i <= S; ++ i ){
      L[i] = i - 1;
      R[i] = i + 1;
    }
    while( B -- ){
      int lhs {}, rhs {};
      cin >> lhs >> rhs;
      R[L[lhs]] = R[rhs];
      L[R[rhs]] = L[lhs];
      if( L[lhs] > 0 )
	cout << L[lhs];
      else
	cout << "*";
      if( R[rhs] <= S )
	cout << " " << R[rhs];
      else
	cout << " *";
      cout << '\n';
    }
    cout << "-\n";
  }
  return 0;
}
