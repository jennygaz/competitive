#include <bits/stdc++.h>
using namespace std;

class UFDS{
private:
  unordered_map<int, int> parent, rank, set_size;
  int num_sets;
  constexpr int NO_SET = (int)(~0U >> 1);
public:
  UFDS() {}
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

/*
// UFDS taken from CP4 by Steven Halim
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};
 */
