#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
bool check_hashmaps( unordered_map<char, int>& lhs, unordered_map<char, int>& rhs ){
  for( auto& keyval : lhs ){
    if( rhs.find( keyval.first ) == rhs.end() )
      return false;
    if( rhs[keyval.first] != keyval.second )
      return false;
  }
  return true;
}

bool check_contains( unordered_map<char, int>& lhs, unordered_map<char, int>& rhs ){
  for( auto& keyval : lhs ){
    if( rhs.find( keyval.first ) == rhs.end() )
      return false;
    if( rhs[keyval.first] < keyval.second )
      return false;
  }
  return true;
}


int minLengthSubstring(string s, string t) {
  unordered_map<char, int> window;
  unordered_map<char, int> t_vals, s_vals;
  for( auto& c : t )
    t_vals[c] ++;
  for( auto& c : s )
    s_vals[c] ++;
  if( not check_contains( t_vals, s_vals ) )
    return -1;
  int passes[3] = {1e7, 1e8, 1e9};
  for( int i = 0; i < (int)s.length(); ++ i ){
    window[s[i]] ++;
    if( check_hashmaps( t_vals, window ) ){
      passes[0] = i;
      break;
    }
  }
  for( int i = 0; i < passes[0]; ++ i ){
    window[s[i]] --;
    if( not check_hashmaps( t_vals, window ) ){
      passes[1] = i - 1;
      break;
    }
  }
  for( int i = passes[0]; i < (int)s.length(); ++ i ){
    window[s[i]] ++;
    if( check_hashmaps( t_vals, window ) ){
      passes[2] = i;
      break;
    }
  }
  cerr << "passes:" << endl << "\t0 -> " << passes[0]
    << "\n\t1 -> " << passes[1] << "\n\t2 -> " << passes[2] << endl;
  return min( passes[0] - passes[1], passes[2] - passes[1] );
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
