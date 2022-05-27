#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int hamming( const string& lhs, const string& rhs ){
  int dist {};
  for( int i = 0; i < (int)lhs.length(); ++ i )
    if( lhs[i] != rhs[i] ) ++ dist;
  return dist;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int movies {}, queries {};
  cin >> movies >> queries;
  string query {};
  vector<string> db( movies );
  for( int i = 0; i < movies; ++ i )
    cin >> db[i];
  while( queries -- ){
    cin >> query;
    int best {200}; // max length is 100, good dummy value
    int best_idx {}; // best index
    for( int i = 0; i < movies; ++ i ){
      if( db[i].length() < query.length() ) continue;
      for( int j = 0; j <= (int)(db[i].length() - query.length()); ++ j ){
	int dist = hamming( db[i].substr( j, query.length() ), query );
	if( dist < best or (dist == best and i < best_idx) ){
	  best = dist;
	  best_idx = i;
	}
      }
    }
    cout << best_idx + 1 << '\n';
  }
  return 0;
}
