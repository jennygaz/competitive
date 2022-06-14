#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int digits {}, to_erase {};
  string num {};
  while( cin >> digits >> to_erase, digits | to_erase ){
    cin >> num;
    int erased{to_erase};
    for( int i = 0; erased and i < digits; ){
      if( num[i] < num[i + 1] ){
	num.erase( num.begin() + i );
	-- erased;
	if( erased == 0 ) break;
	i = max( i - 1, 0 );
      }
      else ++ i;
    }
    cout << string(num.begin(), num.begin() + (digits - to_erase)) << '\n';
  }
  return 0;
}
