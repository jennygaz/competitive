/* UVa 10978 - Let's play magic! */
/* solution 2: use a next/prev array as in Army Buddies */
/* by jennyga */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MAXN = 52;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, available {};
  int LHS[MAXN] {}, RHS[MAXN] {}, val[MAXN] {};
  vector<string> cards( MAXN ), words( MAXN );
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i ){
      cin >> cards[i] >> words[i];
      RHS[i] = (i + 1) % n;
      LHS[i] = (i - 1 + n) % n;
    }
    available = (1 << n) - 1;
    int pos_idx = 0, word_idx {};
    int word_size = words[word_idx].length();
    while( available ){
      -- word_size;
      if( word_size == 0 ){
	val[pos_idx] = word_idx;
	word_idx ++;
	available &= ~(1 << pos_idx);
	if( available )
	  word_size = words[word_idx].length();
	int tmp_rhs = RHS[pos_idx], tmp_lhs = LHS[pos_idx];
	RHS[tmp_lhs] = tmp_rhs;
	LHS[tmp_rhs] = tmp_lhs;
      }
      pos_idx = RHS[pos_idx];
    }
    for( int i = 0; i < n; ++ i )
      cout << cards[val[i]] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
