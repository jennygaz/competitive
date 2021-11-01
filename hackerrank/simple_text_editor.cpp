#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pair<int, string> last_op {};
  vector<string> st {};
  int q {}, st_len {};
  cin >> q;
  while( q -- ){
    int op {}, idx {};
    string str {};
    cin >> op;
    if( op == 1 ){
      cin >> str;
      st.emplace_back( str );
      st_len += str.length();
      last_op.first = 1;
      last_op.second = std::move( str );
    }
    else if( op == 2 ){
      cin >> idx;
      int chunk_len {idx};
      stack<string> chunks {};
      while( idx > 0 ){
	if( (int)st.back().length() <= idx ){
	  idx -= st.back().length();
	  chunks.emplace( st.back() );
	  st.pop_back();
	}
	else{
	  string tmp_back = st.back();
	  chunks.emplace( tmp_back.substr( tmp_back.length() - idx, idx ) );
	  tmp_back = tmp_back.substr( 0, tmp_back.length() - idx );
	  st.pop_back();
	  st.emplace_back( tmp_back );
	  idx = 0;
	}
      }
      string op_str( chunk_len, '0' );
      int abs_idx {};
      while( not chunks.empty() ){
	str = chunks.top();
        for( int curr_idx {}; curr_idx < (int)str.length(); ++ curr_idx )
	  op_str[abs_idx ++] = str[curr_idx];
	chunks.pop();
      }
      last_op.first = 2;
      last_op.second = std::move( op_str );
    }
    else if( op == 3 ){
      cin >> idx;
      int st_idx = st.size() - 1;
      while( st_idx > 0 and idx > (int)st[st_idx].length() )
	idx -= st[st_idx --].length();
      int curr_len = st[st_idx].size();
      cout << st[st_idx][curr_len - 1 - idx] << '\n';
    }
    else{
      if( last_op.first == 1 ){
	st.pop_back();
	last_op.first = 0;
	last_op.second = "";
      }
      else if( last_op.first == 2 ){
	st.emplace_back( last_op.second );
	last_op.first = 0;
	last_op.second = "";
      }
    }
  }
  return 0;
}
