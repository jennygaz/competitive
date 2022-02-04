/* UVa 417 - Word Index */
/* Solution: Store the valid words in a map and always check if the incoming words are in it or not */
/* by jennyga */

#include <iostream>
#include <unordered_map>

using namespace std;

void init( unordered_map<string, int>& valid ){
  int val {1};
  string key = "*";
  for( char first = 'a'; first <= 'z'; ++ first ){
    key[0] = first;
    valid[key] = val;
    ++ val;
  }
  key = "**";
  for( char first = 'a'; first < 'z'; ++ first ){
    key[0] = first;
    for( char second = first + 1; second <= 'z'; ++ second ){
      key[1] = second;
      valid[key] = val;
      ++ val;
    }
  }
  key = "***";
  for( char first = 'a'; first < 'y'; ++ first ){
    key[0] = first;
    for( char second = first + 1; second < 'z'; ++ second ){
      key[1] = second;
      for( char third = second + 1; third <= 'z'; ++ third ){
	key[2] = third;
	valid[key] = val;
	++ val;
      }
    }
  }
  key = "****";
  for( char first = 'a'; first < 'x'; ++ first ){
    key[0] = first;
    for( char second = first + 1; second < 'y'; ++ second ){
      key[1] = second;
      for( char third = second + 1; third < 'z'; ++ third ){
	key[2] = third;
	for( char fourth = third + 1; fourth <= 'z'; ++ fourth ){
	  key[3] = fourth;
	  valid[key] = val;
	  ++ val;
	}
      }
    }
  }
  key = "*****";
  for( char first = 'a'; first < 'w'; ++ first ){
    key[0] = first;
    for( char second = first + 1; second < 'x'; ++ second ){
      key[1] = second;
      for( char third = second + 1; third < 'y'; ++ third ){
	key[2] = third;
	for( char fourth = third + 1; fourth < 'z'; ++ fourth ){
	  key[3] = fourth;
	  for( char fifth = fourth + 1; fifth <= 'z'; ++ fifth ){
	    key[4] = fifth;
	    valid[key] = val;
	    ++ val;
	  }
	}
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string key {};
  unordered_map<string, int> valid {};
  init( valid );
  while( cin >> key )
    cout << valid[key] << '\n';
  return 0;
}
