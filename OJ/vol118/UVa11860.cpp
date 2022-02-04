/* UVa 11860 - Document Analyzer */
/* Solution: Two Pointers plus iterate over every new word and check if you have hit all the words already or not */
/* by jennyga, code from my previous account, jocagos */

#include <cstring>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
constexpr int MAXC = 155;
constexpr int MAXN = 100010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  int nums[MAXN] {};
  int used[MAXN] {};
  for( int DOC = 1; DOC <= tc; ++ DOC){
    memset( used, false, sizeof used );
    unordered_map<string, int> words;
    int word_idx {1}, arr_idx {1};
    getline( cin, line );
    while( line != "END" ){
      int L {}, R {};
      bool match {};
      while( L < (int)line.length() ){
	while( match ){
	  if( R < (int)line.length() and 'a' <= line[R] and line[R] <= 'z' )
	    ++ R;
	  else{
	    match = false;
	    string tmp = line.substr( L, R - L );
	    if( words.find( tmp ) == words.end() )
	      words[tmp] = word_idx ++;
	    nums[arr_idx ++] = words[tmp];
	    L = R;
	  }
	}
	if( 'a' <= line[L] and line[L] <= 'z' ){
	  match = true;
	  R = L + 1;
	}
	else
	  ++ L;
      }
      getline( cin, line );
    }
    // using two-pointers/sliding window to solve it
    int L {1}, R {1}, W {word_idx - 1};
    int best_L {word_idx}, best_R {word_idx}, best_len {MAXN};
    // When W is 0, we have found a possible solution.
    // Hence, we need to increase L as much as possible.
    // Keep track of the best solution so far, too (L, R, len)
    while( L < arr_idx ){
      if( R < arr_idx and not used[nums[R]] )
	-- W;
      if( W == 0 ){
	while( used[nums[L]] > 1 ){
	  -- used[nums[L]];
	  ++ L;
	}
	if( best_len > (R - L + 1) ){
	  best_len = R - L + 1;
	  best_L = L;
	  best_R = R;
	}
	-- used[nums[L]];
	++ L;
	++ W;
      }
      if( R < arr_idx ){
	++ used[nums[R]];
	++ R;
      }
      else if( W )
	  break;
    }
    cout << "Document " << DOC << ": "
	 << best_L << " " << best_R << '\n';
  }
  return 0;
}
