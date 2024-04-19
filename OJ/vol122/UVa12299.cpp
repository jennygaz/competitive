#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

constexpr int LAZY_DEFAULT = -1;

class SegmentTree {
private:
  int n {};
  vector<int> st {}, lazy {};

  int lhs(int p) { return p << 1; }
  int rhs(int p) { return (p << 1) + 1; }

  int conquer(int a, int b) {
    if( a == -1 ) return b;
    if( b == -1 ) return a;
    return min(a, b);
  }

  void build(int p, int left, int right) {
    if( left == right ) st[p] = A[left];
    else {
      int mid = (left + right) / 2;
      build(lhs(p), left, mid);
      build(rhs(p), mid + 1, right);
      st[p] = conquer(st[lhs(p)], st[rhs(p)]);
    }
  }

  void propagate(int p, int left, int right) {
    if( lazy[p] == LAZY_DEFAULT ) return;
    st[p] = lazy[p];
    if( left != right) lazy[lhs(p)] = lazy[rhs(p)] = lazy[p];
    else A[left] = lazy[p];
    lazy[p] = LAZY_DEFAULT;
  }

  int rmq(int p, int left, int right, int from, int to) {
    propagate(p, left, right);
    if( from > to ) return -1;
    if( (left >= from) and (right <= to) ) return st[p];
    int mid = (left + right) / 2;
    return conquer(rmq(lhs(p), left,    mid,   from,               min(mid, to)),
		   rmq(rhs(p), mid + 1, right, max(from, mid + 1), to));
  }

  void update(int p, int left, int right, int from, int to, int val) {
    propagate(p, left, right);
    if( from > to ) return;
    if( (left >= from) and (right <= to) ) {
      lazy[p] = val;
      propagate(p, left, right);
    } else {
      int mid = (left + right) / 2;
      update(lhs(p), left,    mid,   from,               min(mid, to), val);
      update(rhs(p), mid + 1, right, max(from, mid + 1), to,           val);
      int lhs_res = (lazy[lhs(p)] != LAZY_DEFAULT) ? lazy[lhs(p)] : st[lhs(p)];
      int rhs_res = (lazy[rhs(p)] != LAZY_DEFAULT) ? lazy[rhs(p)] : st[rhs(p)];
      st[p] = conquer(lhs_res, rhs_res);
    }
  }

public:
  vector<int> A {};
  SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, LAZY_DEFAULT) {}
  SegmentTree(const vector<int>& start_arr) : SegmentTree((int)start_arr.size()) {
    A = start_arr;
    build(1, 0, n - 1);
  }

  void update(int from, int to, int val) { update(1, 0, n - 1, from, to, val); }

  int rmq(int from, int to) { return rmq(1, 0, n - 1, from, to); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, q {};
  cin >> n >> q;
  string command {};
  vector<int> values( n, 0 );
  for( int i = 0; i < n; ++ i ) cin >> values[i];
  SegmentTree st(values);
  while( q -- ) {
    cin >> command;
    string str = command.substr(6, command.length() - 7 );
    transform( str.begin(), str.end(), str.begin(), []( char& c ) -> char {
      return (c == ',' ? c = ' ' : c);
    });
    istringstream iss(str);
    if( command[0] == 'q' ) {
      int a {}, b {};
      iss >> a >> b;
      -- a; -- b;
      cout << st.rmq(a, b) << '\n';
    } else if( command[0] == 's' ) {
      vector<int> shifted {};
      shifted.reserve(30);
      int tmp {};
      while( iss >> tmp ) {
	shifted.emplace_back( tmp - 1 );
      }
      tmp = st.rmq(shifted[0], shifted[0]);
      for( int i = 0; i < (int)shifted.size() - 1; ++ i ) {
	int index = shifted[i];
	int next = shifted[i + 1];
	int point_val = st.rmq(next, next);
	st.update(index, index, point_val);
      }
      st.update(shifted[shifted.size() - 1], shifted[shifted.size() - 1], tmp);
    }
  }
  return 0;
}
