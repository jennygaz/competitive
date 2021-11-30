#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  const string GRANTED = "GRANTED\n", DENIED = "DENIED\n", IGNORED = "IGNORED\n";
  string line {}, mode {};
  int tc {}, trid {}, val {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    getline( cin, line ); // blank
    unordered_set<int> blocked {};
    unordered_map<int, int> exclusive {};
    unordered_map<int, unordered_set<int>> item_trid {};
    while( getline( cin, line ), line[0] != '#' ){
      istringstream iss( line );
      iss >> mode >> trid >> val;
      // On the blocklist already, just ignore
      if( blocked.find( trid ) != blocked.end() )
	cout << IGNORED;
      // if they have different trid and there's an exclusive lock for one of them
      // Exclusive lock with different trid
      else if( (exclusive.find( val ) != exclusive.end() and exclusive[val] != trid) or
	       (mode[0] == 'X' and item_trid.find( val ) != item_trid.end() and
		(item_trid[val].size() > 1 or
		 (item_trid[val].size() == 1 and *item_trid[val].begin() != trid) ) ) ){
	blocked.emplace( trid );
	cout << DENIED;
      }
      else{
	if( mode[0] == 'S' ){
	  item_trid[val].emplace( trid );
	  cout << GRANTED;
	}
	else if( mode[0] == 'X' ){
	  exclusive[val] = trid;
	  cout << GRANTED;
	}
      }
    }
    if( tc ) cout << '\n';
  }
  return 0;
}
