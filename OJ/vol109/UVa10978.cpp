/* UVa 10978 - Let's play magic! */
/* solution 1: skip the value */
/* by jennyga */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int MAXN = 52; // max ring-buffer size

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {};
  unsigned long long available = 0; // better to use uint64_t but we need 52+ bits always
  vector<string> words( MAXN ), cards( MAXN );
  vector<int> positions( MAXN );
  while( cin >> n, n ){
    for( int i = 0; i < n; ++ i )
      cin >> cards[i] >> words[i];
    available = (1 << n) - 1; // quickly set n first bits
    int pos_idx {}, bit_idx {}, word_size = words[0].length();
    while( available ){
      word_size -= (bool)(available & (1 << bit_idx)); // check `bit_idx` bit
      if( word_size == 0 ){
	positions[bit_idx] = pos_idx;
	++ pos_idx;
	if( available )
	  word_size = words[pos_idx].length();
	available &= ~(1 << bit_idx);
      }
      bit_idx = (bit_idx + 1) % n;
    }
    for( int i = 0; i < n; ++ i )
      cout << cards[positions[i]] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
