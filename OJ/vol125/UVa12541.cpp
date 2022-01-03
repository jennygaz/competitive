/* UVa 12541 - Birthdates */
/* Solution: Get all the data then sort it */
/* by jennyga */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  int day {}, month {}, year {};
  string name {};
  cin >> n;
  vector<tuple<int, int, int, string>> data {};
  data.reserve( n );
  for( int i = 0; i < n; ++ i ){
    cin >> name >> day >> month >> year;
    data.emplace_back( year, month, day, name );
  }
  sort( data.begin(), data.end() );
  cout << get<3>( data.back() ) << '\n' << get<3>( data[0] ) << '\n';
  return 0;
}
