#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int matchingPairs(string s, string t) {
  int ans {};
  bool dupe {};
  auto pair_hash = []( const std::pair<char, char>& p ) -> int { return 256 * p.first + p.second; };
  unordered_set<pair<char, char>, decltype(pair_hash)> matchless( 8, pair_hash );
  unordered_set<char> used;
  for( int i = 0; i < (int)s.length(); ++ i ){
    if( s[i] == t[i] ){
      ++ ans;
      if( used.find( s[i] ) != used.end() )
        dupe = true;
      used.emplace( s[i] );
    }
    else
      matchless.emplace( s[i], t[i] );
  }
  if( ans == (int)s.length() ) return dupe ? ans : ans - 2;
  if( ans == (int)s.length() - 1 ){
    auto rem = *matchless.begin();
    if( dupe or used.find( rem.first ) != used.end() or used.find( rem.second ) != used.end() )
      return ans;
    return ans - 1;
  }
  for( auto& vals : matchless )
    if( matchless.find( pair<char, char>( vals.second, vals.first ) ) != matchless.end() )
      return ans + 2;
  unordered_set<char> rem_ss, rem_tt;
  for( auto& vals : matchless ){
    if( rem_ss.find( vals.second ) != rem_ss.end() or rem_tt.find( vals.second ) != rem_tt.end() )
      return ans + 1;
    rem_ss.emplace( vals.first );
    rem_tt.emplace( vals.second );
  }
  return ans;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
