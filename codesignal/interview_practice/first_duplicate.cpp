#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <cmath>

using namespace std;

/*
 * O(n^2) time, O(1) space solution
 * Iterate over all the elements, for each one, iterate and seek if there's a duplicate
 */

inline int first_duplicate_quadratic( vector<int> a ){
  int idx = a.size() + 1;
  for( int i {}; i < (int)a.size(); ++ i ){
    for( int j {i + 1}; j < (int)a.size(); ++ j ){
      if( a[i] == a[j] )
	idx = min( idx, j );
    }
  }
  return (idx == (int)a.size() + 1 ? -1 : a[idx]);
}

/* 
 * O(nlgn) time, O(n) space solution
 * Create a new array with tuples (value, idx), where we can easily see the first duplicate in a O(n) pass
 */

inline int first_duplicate_nlogn( vector<int> a ){
  vector<tuple<int, int>> dupes;
  dupes.reserve( a.size() );
  for( int idx {}; idx < (int)a.size(); ++ idx )
    dupes.emplace_back( a[idx], idx );
  sort( dupes.begin(), dupes.end() );
  int idx = a.size() + 1;
  for( int i {1}; i < (int)dupes.size(); ++ i )
    if( get<0>( dupes[i] ) == get<0>( dupes[i - 1] ) )
      idx = min( idx, get<1>( dupes[i] ) );
  return (idx == a.size() + 1 ? -1 : a[idx]);
}

/*
 * O(n) time, O(n) space solution
 * Use a Hashset, while keeping count of the index and updating it.
 */

inline int first_duplicate_linear( vector<int> a ){
  int idx = a.size() + 1;
  unordered_set<int> hash_set;
  for( int i {}; i < (int)a.size(); ++ i ){
    if( hash_set.find( a[i] ) == hash_set.end() )
      hash_set.emplace( a[i] );
    else
      idx = min( idx, i );
  }
  return (idx == a.size() + 1 ? -1 : a[idx]);
}

/*
 * O(n) time, O(1) space (conditional) solution
 * Use the array to mark the values used (since all are in [1, a.size()], just offset by 1 afterwards)
 * Very similar to the previous solution, but with constrained space
 * and under the assumption that we can modify this array
 */

inline int first_duplicate( vector<int> a ){
  int idx = a.size() + 1;
  for( int i {}; i < (int)a.size(); ++ i ){
    // -1 is used to offset the [1, a.size()] range to [0, a.size()-1], which are valid indexes
    if( a[abs(a[i]) - 1] > 0 ) // not yet used
      a[abs(a[i]) - 1] *= -1; // mark it as used
    else // the value a[i] has been used!
      idx = min( idx, i );
  }
  return (idx == a.size() + 1 ? -1 : abs(a[idx]));
}

int main(){
  return 0;
}
