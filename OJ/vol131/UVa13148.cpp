/* UVa 13148 - A Giveaway */
/* Solution: Just check if a number is any of the ones given, either with a set or many ifs */
/* by jennyga */

#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_set<int> keys( {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121} );
  int val {};
  while( cin >> val, val ){
    if( keys.find( val ) != keys.end() )
      cout << "Special\n";
    else
      cout << "Ordinary\n";
  }
  return 0;
}
