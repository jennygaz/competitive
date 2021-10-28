#include <bits/stdc++.h>

using namespace std;

vector<int> contiguous_subarrays( vector<int> arr ){
  vector<int> ans( arr.size(), 1 );
  stack<int> st {};
  int lhs_idx {};
  st.push( lhs_idx );
  for( lhs_idx = 1; lhs_idx < (int)arr.size(); ++ lhs_idx ){
    // keep popping until the value from the index in st is greater
    while( not st.empty() and arr[st.top()] < arr[lhs_idx] )
      st.pop();
    int rhs_idx {};
    if( st.empty() )
      rhs_idx = -1;
    else
      rhs_idx = st.top();
    ans[lhs_idx] += lhs_idx - rhs_idx - 1;
    st.push( lhs_idx );
  }
  // clear it and do it from the other side now
  while( not st.empty() ) st.pop();
  st.push( arr.size() - 1 );
  for( lhs_idx = arr.size() - 2; lhs_idx >= 0; -- lhs_idx ){
    while( not st.empty() and arr[st.top()] < arr[lhs_idx] )
      st.pop();
    int rhs_idx {};
    if( st.empty() )
      rhs_idx = arr.size();
    else
      rhs_idx = st.top();
    ans[lhs_idx] += rhs_idx - lhs_idx - 1;
    st.push( lhs_idx );
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> test( {3, 4, 1, 6, 2} );
  vector<int> ans = contiguous_subarrays( test );
  for( auto& val : ans )
    cout << val << ' ';
  cout << endl;
  return 0;
}
