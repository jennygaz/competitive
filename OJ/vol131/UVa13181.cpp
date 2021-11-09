#include <cstdio>

using namespace std;

constexpr int MAXN = 500500;

inline int max( int lhs, int rhs ){
  return (lhs > rhs ? lhs : rhs);
}

int main(){
  char c {};
  int n {}, p {}, L {}, R {};
  int pos[MAXN] {};
  while( (c = getchar_unlocked()) != -1 ){
    if( c == '\n' ){
      L = pos[0];
      R = pos[p - 1];
      int max_val = max( L - 1, n - 1 - R - 1 );
      for( int i = 0; i < p - 1; ++ i )
	max_val = max( max_val, ((pos[i + 1] - pos[i] - 1) - 1) >> 1 );
      printf("%d\n", max_val);
      L = R = n = p = 0;
    }
    else{
      if( c == 'X' )
	pos[p ++] = n;
      ++ n;
    }
  }
  return 0;
}
