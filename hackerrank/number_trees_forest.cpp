#include <bits/stdc++.h>
using namespace std;

class UFDS{
private:
  unordered_map<int, int> parent, rank, set_size;
  int num_sets;
  static constexpr int NO_SET = (int)(~0U >> 1);
public:
  UFDS() : num_sets(0) {}
  UFDS( int N ){
    for( int i = 0; i < N; ++ i ){
      parent[i] = i;
      rank[i] = 0;
      set_size[i] = 1;
    }
    num_sets = N;
  }
  int find_set( int i ){
    if( parent.find( i ) != parent.end() )
      return parent[i] == i ? i : parent[i] = find_set( i );
    else
      return NO_SET;
  }
  bool is_same_set( int lhs, int rhs ){
    int p_lhs = find_set( lhs ), p_rhs = find_set( rhs );
    return p_lhs == p_rhs and p_lhs != NO_SET;
  }
  int disjoint_sets(){
    return num_sets;
  }
  int size_of_set( int i ){
    int p_i = find_set( i );
    if( p_i != NO_SET )
      return set_size[p_i];
  }
  void union_set( int lhs, int rhs ){
    int p_lhs = find_set( lhs ), p_rhs = find_set( rhs );
    // both in the UFDS, and distinct
    if( p_lhs != NO_SET and p_rhs != NO_SET and p_lhs != p_rhs ){
      if( rank[p_lhs] > rank[p_rhs] ) swap( p_lhs, p_rhs );
      parent[p_lhs] = p_rhs;
      if( rank[p_lhs] == rank[p_rhs] ) ++ rank[p_rhs];
      set_size[p_rhs] += set_size[p_lhs];
      -- num_sets;
    }
    else if( p_lhs != NO_SET and p_rhs == NO_SET ){
      parent[rhs] = p_lhs;
      ++ rank[p_lhs];
      ++ set_size[p_lhs];
    }
    else if( p_rhs != NO_SET and p_lhs == NO_SET ){
      parent[lhs] = p_rhs;
      ++ rank[p_rhs];
      ++ set_size[p_rhs];
    }
    else{
      parent[rhs] = parent[lhs] = lhs;
      ++ num_sets;
      set_size[lhs] = 2;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int nodes {};
  cin >> nodes;
  UFDS ufds;
  while( nodes -- ){
    int lhs {}, rhs {};
    cin >> lhs >> rhs;
    ufds.union_set( lhs, rhs );
  }
  cout << ufds.disjoint_sets() << '\n';
  return 0;
}
