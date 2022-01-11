/* UVa 11321 - Sort! Sort!! and Sort!!! */
/* Taken from a previous personal submission */

#include <stdlib.h>
#include <stdio.h>

void fastscan(int * number)
{
  char negative = 0;
  register int c;
  *number = 0;
  c = getchar();
  if (c=='-') negative = 1, c = getchar();
  for (; (c>='0' && c<='9'); c=getchar())
    *number = (*number) *10 + c - '0';
  if (negative)
    *number *= -1;
}

void fastscanl(long * number)
{
  char negative = 0;
  register int c;
  *number = 0;
  c = getchar();
  if (c=='-') negative = 1, c = getchar();
  for (; (c>='0' && c<='9'); c=getchar())
    *number = (*number) * 10 + c - '0';
  if (negative)
    *number *= -1;
}

int m;

int cmp( const void * left, const void * right ){
  long l = *((long *) left), r = *((long *) right);
  int first = (l % m) - (r % m);
  if( first ) return first;
  else{
    int _l = l & 1, _r = r & 1, sum = _l + _r;
    if( sum == 1 ) return (_l & 1 ? -1 : 1);
    else if( sum == 2 ) return (l < r ? 1 : -1);
    else if( sum == 0 ) return (l < r ? -1 : 1);
  }
}

int main(){
  int n, i;
  long vals[10001];
  while( (fastscan(&n), fastscan(&m)), n | m ){
    for( i = 0; i < n; ++ i ) fastscanl((vals + i));
    qsort( vals, n, sizeof(long), cmp );
    printf("%d %d\n", n, m);
    for( i = 0; i < n; ++ i ) printf("%ld\n", vals[i]);
  }
  printf("%d %d\n", n, m);
  return 0;
}
