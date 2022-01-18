/* UVa 12720 - Algorithm of Phil */
/* Solution: Two pointers on a bitmask */
/* by jennyga */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
constexpr int MAX_LEN = 100100;
constexpr unsigned long long int MOD = 1e9 + 7;

int main(){
  int tc {};
  char buf[MAX_LEN] {};
  fgets( buf, MAX_LEN, stdin );
  sscanf( buf, "%d", &tc );
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    fgets( buf, MAX_LEN, stdin );
    int len = strlen( buf );
    buf[len --] = '\0'; // fill the line end
    int L {}, R {}, tmp_len {len};
    if( len & 1 ){
      L = R = len / 2;
    }
    else{
      L = len / 2 - 1;
      R = len / 2;
    }
    unsigned long long ans {};
    while( tmp_len ){
      if( tmp_len & 1 ){ // odd
	if( L + 1 == len - R ){ // first on odd length
	  ans = ((ans << 1) + (buf[R] - '0')) % MOD;
	  -- L;
	  ++ R;
	}
	else if( L + 1 < len - R ){ // right side has more values
	  ans = ((ans << 1) + (buf[R] - '0')) % MOD;
	  ++ R;
	}
	else{ // left side has more values
	  ans = ((ans << 1) + (buf[L] - '0')) % MOD;
	  -- L;
	}
      }
      else{ // even
	if( L + 1 == len - R ){ // take one of them
	  if( buf[R] > buf[L] ){
	    ans = ((ans << 1) + (buf[R] - '0')) % MOD;
	    ++ R;
	  }
	  else{
	    ans = ((ans << 1) + (buf[L] - '0')) % MOD;
	    -- L;
	  }
	}
      }
      -- tmp_len;
    }
    printf("Case #%d: %llu\n", CASE, ans );
  }
  return 0;
}
