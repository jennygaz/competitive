/* UVa 499 - What's the Frequency? */
/* Solution: Use a `map` or an array for ASCII chars and get the max, then anyone tied */
/* by jennyga */

#include <cstdio>
#include <cstring>

using namespace std;
constexpr int MAXC = 255;

int main(){
  int counts[MAXC] {};
  char c {};
  while( (c = getc(stdin)) != EOF ){
    ++ counts[c];
    if( c == '\n' ){
      int max_val {};
      for( int i = 0; i < MAXC; ++ i )
	if( (('a' <= i and i <= 'z') or ('A' <= i and i <= 'Z')) and counts[i] > max_val )
	  max_val = counts[i];
      for( int i = 0; i < MAXC; ++ i )
	if( (('a' <= i and i <= 'z') or ('A' <= i and i <= 'Z')) and counts[i] == max_val )
	  printf("%c", i);
      printf(" %d\n", max_val);
      memset( counts, 0, sizeof counts );
    }
  }
  return 0;
}
