/* UVa 11629 - Ballot Evaluation */
/* Solution: store the parties as strings, use them to access a map, check the equation given */
/* by jennyga */

#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char dot {};
  int parties {}, guesses {}, val_int {}, val_dec {};
  cin >> parties >> guesses;
  unordered_map<string, pair<int, int>> values {};
  string party_name {}, oper {};
  for( int i = 0; i < parties; ++ i ){
    cin >> party_name >> val_int >> dot >> val_dec;
    values[party_name] = { val_int, val_dec };
  }
  for( int i = 0; i < guesses; ++ i ){
    int total {}, rhs {};
    while( oper[0] != '=' and oper[0] != '<' and oper[0] != '>' ){
      cin >> party_name >> oper;
      total += values[party_name].first * 10 + values[party_name].second;
    }
    cin >> rhs;
    rhs *= 10;
    bool res {};
    if( oper == "=" )
      res = (total == rhs);
    else if( oper == "<" )
      res = (total < rhs);
    else if( oper == ">" )
      res = (total > rhs);
    else if( oper == "<=" )
      res = (total <= rhs);
    else if( oper == ">=" )
      res = (total >= rhs);
    cout << "Guess #" << (i+1) << " was " << (res ? "" : "in") << "correct.\n";
    oper = "";
  }
  return 0;
}
