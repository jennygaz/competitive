/* UVa 10138 - CDXVII */
/* Solution: Use a hashmap for the prices, or an array, then a hashmap for the entrances and exits */
/* by jennyga */

#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <functional>

using namespace std;

constexpr int MAX_PLATE = 1010, MAX_TOLLS = 25;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  getline( cin, line ); // get blank line
  int tolls[MAX_TOLLS] {};
  tuple<int, int, string, int> plates[MAX_PLATE] {};
  while( tc -- ){
    getline( cin, line ); // get fares
    istringstream tolls_parser( line );
    int curr_toll {}, idx {};
    while( tolls_parser >> curr_toll )
      tolls[idx ++] = curr_toll;
    unordered_map<string, int> entrances {},  toll_used {};
    map<string, int> costs {};
    int plate_idx {};
    while( getline( cin, line ), line != "" ){
      string plate {}, use_type {};
      int month {}, day {}, hour {}, minute {}, km {};
      char colon {};
      istringstream line_parser( line );
      line_parser >> plate >> month >> colon >> day >> colon >> hour >> colon >> minute >> use_type >> km;
      plates[plate_idx ++] = { minute + hour * 60 + day * 10000 + month * 1000000, (int)(use_type[1] == 'x'), plate, km };
    }
    sort( plates, plates + plate_idx );
    for( int i = 0; i < plate_idx; ++ i ){
      int toll_idx = get<0>( plates[i] ) % 10000 / 60;
      int km_used = get<3>( plates[i] );
      string plate_name = get<2>( plates[i] );
      if( get<1>( plates[i] ) == 0 ){ // enter
	toll_used[plate_name] = tolls[toll_idx];
	entrances[plate_name] = km_used;
      }
      else if( get<1>( plates[i] ) == 1 ){ // exit
	if( entrances.find( plate_name ) != entrances.end() ){
	  costs[plate_name] += abs( km_used - entrances[plate_name] ) * toll_used[plate_name] + 100;
	  entrances.erase( plate_name );
	}
      }
    }
    for( auto& bill : costs )
      cout << bill.first << " $" << bill.second / 100 + 2 << "."
	   << setw( 2 ) << setfill('0') << bill.second % 100 << '\n';
    if( tc ) cout << '\n';
  }
  return 0;
}
