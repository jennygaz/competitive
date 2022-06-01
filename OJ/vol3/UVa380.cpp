#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
constexpr int MAX_TIMEPOINT = 10000;
constexpr int MAX_PHONES = 110;
constexpr int NOT_SET = -1;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<int>> adj_lists( MAX_TIMEPOINT, vector<int>( MAX_PHONES, NOT_SET ) );
  unordered_map<string, int> key2idx;
  vector<string> idx2key(MAX_PHONES);
  unordered_set<string> keys {};
  int tc {}, phones {};
  string token {};
  cin >> tc;
  while( cin >> token, token != "0000" ){
    string time {}, duration {}, target {};
    cin >> time >> duration >> target;
    if( keys.find( token ) == keys.end() ){
      idx2key[(int)keys.size()] = token;
      key2idx[token] = keys.size();
      keys.emplace( token );
      ++ phones;
    }
    if( keys.find( target ) == keys.end() ){
      idx2key[(int)keys.size()] = target;
      key2idx[target] = keys.size();
      keys.emplace( target );
      ++ phones;
    }
    int timepoint = stoi( time );
    int cycles = stoi( duration );
    for( int tp = timepoint; tp <= cycles + timepoint; ++ tp ){
      adj_lists[tp][key2idx[token]] = key2idx[target];
    }
  } // end while
  // now simulate the process
  cout << "CALL FORWARDING SYSTEM\n";
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    cout << "SYSTEM " << CASE << '\n';
    while( cin >> token, token != "9000" ){
      string from {};
      cin >> from;
      if( keys.find( from ) == keys.end() ){
	idx2key[(int)keys.size()] = from;
	key2idx[from] = keys.size();
	keys.emplace( from );
	++ phones;
	int timepoint = stoi( token );
	adj_lists[timepoint][key2idx[from]] = key2idx[from];
	cout << "AT " << token << " CALL TO " << from << " RINGS " << from << '\n';
	continue;
      }
      int timepoint = stoi( token );
      int idx = key2idx[from];
      int turtle = idx, hare = idx;
      // find cycles with floyd's turtle and hare algorithm
      while( turtle != NOT_SET and hare != NOT_SET ){
	// if they're ever a -1 (NOT_SET), stop, no cycle
	turtle = adj_lists[timepoint][turtle];
	hare = adj_lists[timepoint][hare];
	if( hare != NOT_SET )
	  hare = adj_lists[timepoint][hare];
	if( turtle == hare ) break;
      }
      cout << "AT " << token << " CALL TO " << from << " RINGS ";
      if( hare == NOT_SET or turtle == NOT_SET ){
	turtle = idx;
	while( adj_lists[timepoint][turtle] != NOT_SET )
	  turtle = adj_lists[timepoint][turtle];
	cout << idx2key[turtle] << '\n';
      }
      else
	cout << "9999\n";
    }
    if( CASE != tc )
      cin >> token; // read the "0000"
  }
  cout << "END OF OUTPUT\n";
  return 0;
}
