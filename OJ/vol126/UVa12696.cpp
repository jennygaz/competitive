/* UVa 12696 - Cabin Baggage */
/* solution: just check the values, read the input and multiply it by 100 */
/* by jennyga */

#include <cstdio>

using namespace std;

constexpr int MAXL = 5600, MAXW = 4500, MAXD = 2500, MAXM = 700, MAXSUM = 12500; // length, width, depth, mass, sum

int main(){
  int n {}, total {};
  scanf("%d", &n);
  while( n -- ){
    int len_lhs {}, len_rhs {}, wid_lhs {}, wid_rhs {}, dep_lhs {}, dep_rhs {}, wgt_lhs {}, wgt_rhs {};
    scanf("%d.%d %d.%d %d.%d %d.%d",
	  &len_lhs, &len_rhs,
	  &wid_lhs, &wid_rhs,
	  &dep_lhs, &dep_rhs,
	  &wgt_lhs, &wgt_rhs );
    int len = len_lhs * 100 + len_rhs;
    int wid = wid_lhs * 100 + wid_rhs;
    int dep = dep_lhs * 100 + dep_rhs;
    int wgt = wgt_lhs * 100 + wgt_rhs;
    if( ((len <= MAXL and wid <= MAXW and dep <= MAXD) or (len + wid + dep <= MAXSUM))
	and wgt <= MAXM){
      printf("1\n");
      ++ total;
    }
    else
      printf("0\n");
  }
  printf("%d\n", total);
  return 0;
}
