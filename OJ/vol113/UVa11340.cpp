/* UVa 11340 - Newspaper */
/* Solution: Use a hashmap with ASCII values as keys */
/* by jennyga */

#include <cstdio>
#include <cstring>

using namespace std;
constexpr int MAXC = 10010, MAXN = 256;

int main(){
  int tc {};
  char line[MAXC] {};
  int costs[MAXN] {};
  scanf("%d\n", &tc);
  while( tc -- ){
    memset( costs, 0, sizeof costs );
    int n {};
    scanf("%d\n", &n);
    for( int i = 0; i < n; ++ i ){
      char c {};
      int val {};
      scanf("%c %d\n", &c, &val);
      costs[c + 128] = val;
    }
    scanf("%d\n", &n);
    int cost {};
    memset( line, 0, sizeof line );
    while( n -- ){
      fgets( line, MAXC, stdin );
      int i {};
      while( line[i] ){
	cost += costs[line[i] + 128];
	++ i;
      }
      memset( line, 0, sizeof line );
    }
    printf("%d.%02d$\n", cost / 100, cost % 100);
  }
  return 0;
}
