constexpr int MAXN = 1000000;

int ft_size = MAXN;
int ft[MAXN] {};

// update nodes that depend on i, by delta
void update( int i, int delta ){
  while( i < ft_size ){
    ft[i] += delta;
    i |= i + 1;
  }
}

// sum of [0, r]
int sum( int r ){
  int res = 0;
  while( r >= 0 ){
    res += ft[r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}

// sum of [l, r]
int sum( int l, int r ){
  return sum(r) - sum(l - 1);
}
