/* UVa 12626 - I Love Pizza */
/* Solution: Just use integer division and min to count the number of possible pizzas to make */
/* by jennyga */

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int MAXC = 256;
constexpr int MAXN = 1000;

inline int min( int lhs, int rhs ){
  return (lhs < rhs ? lhs : rhs);
}

int main(){
  int tc {};
  char line[MAXN] {};
  int counts[MAXC] {};
  scanf("%d\n", &tc);
  while( tc -- ){
    memset( counts, 0, sizeof counts );
    memset( line, 0, sizeof line );
    fgets( line, MAXN, stdin );
    int idx {};
    while( line[idx] )
      ++ counts[line[idx ++]];
    int ans {};
    ans = min( min( min( counts['M'], counts['A'] / 3 ), counts['R'] >> 1 ),
	       min( min( counts['G'], counts['I'] ), counts['T'] ) );
    printf("%d\n", ans);
  }
  return 0;
}
