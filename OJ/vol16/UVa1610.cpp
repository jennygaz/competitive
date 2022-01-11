/* UVa 1610 - Party Games */
/* Solution: Get the middle strings, process them char by char, check corner cases */
/* by jennyga */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 1010;

vector<string> vs( MAXN );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      cin >> vs[i];
    sort( vs.begin(), vs.begin() + n );
    int left_idx = n / 2 - 1, right_idx = n / 2;
    string &L = vs[left_idx], &R = vs[right_idx];
    if( L.length() < R.length() ){
      for( int i = 0; i < (int)L.length(); ++ i ){
	if( L[i] == R[i] or i == (int)L.length() - 1 )
	  cout << (char)L[i];
	else{
	  cout << (char)(L[i] + 1);
	  break;
	}
      }
    } // end if
    else{
      for( int i = 0; i < (int)R.length(); ++ i ){
	if( L[i] == R[i] )
	  cout << (char)L[i];
	else{
	  if( i == (int)R.length() - 1 ){
	    if( i == (int)L.length() - 1 ){
	      cout << (char)L[i];
	      break;
	    }
	    if( L[i] + 1 != R[i] ){
	      cout << (char)(L[i] + 1);
	      break;
	    }
	    else{
	      cout << L[i];
	      for( int j = i + 1; j < (int)L.length(); ++ j ){
		if( j == (int)L.length() - 1 )
		  cout << (char)L[j];
		else if( L[j] != 'Z' ){
		  cout << (char)(L[j] + 1);
		  break;
		}
		else
		  cout << (char)L[j];
	      } // end for j
	      break;
	    } // end else
	  }
	  else{
	    cout << (char)(L[i] + 1);
	    break;
	  }
	} // end if l[i] == r[i]
      }
    }
    cout << '\n';
  }
  return 0;
}
