#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000000, MAXP = 78498;

bool sieve[MAXN]{}; // Check list
vector<int> primes(MAXP);
int pidx {};

void atkin(){
  if (MAXN > 2)
    primes[pidx ++] = 2;
  if (MAXN > 3)
    primes[pidx ++] = 3;

  for (int i = 0; i < MAXN; i++)
    sieve[i] = false;

  for (int x = 1; x * x < MAXN; x++) {
    for (int y = 1; y * y < MAXN; y++) {
      int n = (4 * x * x) + (y * y);
      if (n <= MAXN && (n % 12 == 1 || n % 12 == 5))
	sieve[n] ^= true;
      n = (3 * x * x) + (y * y);
      if (n <= MAXN && n % 12 == 7)
	sieve[n] ^= true;
      n = (3 * x * x) - (y * y);
      if (x > y && n <= MAXN && n % 12 == 11)
	sieve[n] ^= true;
    }
  }
  for (int r = 5; r * r < MAXN; r++) {
    if (sieve[r])
      for (int i = r * r; i < MAXN; i += r * r)
	sieve[i] = false;
  }

  for (int a = 5; a < MAXN; a++)
    if (sieve[a])
      primes[pidx ++] = a;
}

int main(){
  atkin();
  
  return 0;
}
