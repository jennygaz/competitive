// UVa 12996 - Ultimate Mango Challenge
// by @jennygaz

#include <iostream>

using namespace std;

constexpr int MAXN = 11;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int CASES {};
  cin >> CASES;
  for( int CASE {1}; CASE <= CASES; ++ CASE ) {    
    int num_types {}, max_total {};
    int total {};
    bool is_possible = true;
    int mangos[MAXN] {};    
    cin >> num_types >> max_total;
    for( int i = 0; i < num_types; ++ i )
      cin >> mangos[i];
    for( int i = 0; i < num_types; ++ i ) {
      int current {};
      cin >> current;
      if( current >= mangos[i] )
	total += mangos[i];
      else
	is_possible = false;
      if( total > max_total )
	is_possible = false;
    }
    cout << "Case " << CASE << ": " << (is_possible ? "Yes\n" : "No\n");
  }
  return 0;
}
