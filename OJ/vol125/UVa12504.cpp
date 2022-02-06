/* UVa 12504 - Updating a Dictionary */
/* Solution: Hardest part is reading the input, the solution is just having two maps and three sets for the keys */
/* by jennyga */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  while( tc -- ){
    unordered_map<string, string> lhs {}, rhs {};
    set<string> added {}, removed {}, changed {};
    getline( cin, line );
    // remove brackets
    line = line.substr( 1, line.length() - 2 );
    string key_val {};
    istringstream lhs_parser( line );
    // tokenize by commas to get keys with their values
    while( getline( lhs_parser, key_val, ',' ) ){
      // then, get the idx of the colon and get the substrings
      size_t colon_idx = key_val.find_first_of(':');
      string key = key_val.substr( 0, colon_idx );
      string val = key_val.substr( colon_idx + 1 );
      lhs[key] = val;
    }
    // repeat for the other dictionary
    getline( cin, line );
    // remove brackets
    line = line.substr( 1, line.length() - 2 );
    istringstream rhs_parser( line );
    // tokenize by commas to get keys with their values
    while( getline( rhs_parser, key_val, ',' ) ){
      // then, get the idx of the colon and get the substrings
      size_t colon_idx = key_val.find_first_of(':');
      string key = key_val.substr( 0, colon_idx );
      string val = key_val.substr( colon_idx + 1 );
      rhs[key] = val;
    }
    // now, check all the keys: first from lhs, then from rhs
    for( auto& kv : lhs ){
      string key = kv.first, val = kv.second;
      if( rhs.find( key ) == rhs.end() ) // deleted key
	removed.emplace( key );
      else if( rhs[key] != val ) // changed key
	changed.emplace( key );
    }
    // now, check for added keys
    for( auto& kv : rhs )
      if( lhs.find( kv.first ) == lhs.end() ) // added key
	added.emplace( kv.first );
    // print all, but first check if there are changes
    if( added.size() == 0 and removed.size() == 0 and changed.size() == 0 )
      cout << "No changes\n";
    else{
      if( added.size() ){
	cout << "+";
	for( auto it = added.begin(); it != added.end(); ++ it ){
	  cout << *it;
	  if( next( it ) != added.end() ) cout << ',';
	  else cout << '\n';
	}
      }
      if( removed.size() ){
	cout << "-";
	for( auto it = removed.begin(); it != removed.end(); ++ it ){
	  cout << *it;
	  if( next( it ) != removed.end() ) cout << ',';
	  else cout << '\n';
	}
      }
      if( changed.size() ){
	cout << "*";
	for( auto it = changed.begin(); it != changed.end(); ++ it ){
	  cout << *it;
	  if( next( it ) != changed.end() ) cout << ',';
	  else cout << '\n';
	}
      }
    }
    cout << '\n';
  }
  return 0;
}
