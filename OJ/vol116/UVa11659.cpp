#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAXN = 21;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int spies {}, queries {};
  while( cin >> spies >> queries, spies | queries ) {
    int pos_bitmasks[MAXN] {}, neg_bitmasks[MAXN] {};
    while( queries -- ) {
      int spy {}, info {};
      cin >> spy >> info;
      if( info > 0 )
	pos_bitmasks[spy] |= (1 << (info - 1));
      else
	neg_bitmasks[spy] |= (1 << ((-info) - 1));
    }
    int max_bits {}, max_mask = (1 << spies) - 1;
    for( int mask = 1; mask <= max_mask; ++ mask ) {
      int offset = (~mask) & max_mask;
      int bitcount = __builtin_popcount(mask);
      if( bitcount < max_bits ) continue;
      
      bool able = true;
      for( int i = 1; i <= spies and able; ++ i )
	able = not ((mask & (1 << (i - 1)))
	    and ((offset & neg_bitmasks[i]) != neg_bitmasks[i]
		 or (mask & pos_bitmasks[i]) != pos_bitmasks[i]) );
      if( able ) max_bits = (max_bits < bitcount ? bitcount : max_bits);
    }
    cout << max_bits << '\n';
  }
  return 0;
}
