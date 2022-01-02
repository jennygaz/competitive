/* UVa 12667 - Last Blood */
/* Solution: Keep track of the last new accepted team for each problem */
/* by jennyga */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int problems {}, teams {}, verdicts {};
  cin >> problems >> teams >> verdicts;
  unordered_map<string, pair<int, int>> last_blood {};
  vector<unordered_set<char>> solved( teams + 1 );
  string iter = "A";
  for( int i = 0; i < problems; ++ i ){
    last_blood[iter] = {-1, -1};
    ++ iter[0];
  }
  while( verdicts -- ){
    int time {}, team_id {};
    string problem {}, verdict {};
    cin >> time >> team_id >> problem >> verdict;
    if( verdict[0] == 'Y' or verdict[0] == 'y' ){ // no need for wrong answers
      if( solved[team_id].find( problem[0] ) == solved[team_id].end() ){ // not solved it
	solved[team_id].emplace( problem[0] );
	last_blood[problem] = {team_id, time}; // update the team that solved it
      }
    }
  }
  iter = "A";
  for( int i = 0; i < problems; ++ i ){
    cout << iter << " ";
    if( last_blood[iter].first == -1 ) cout << "- -\n";
    else cout << last_blood[iter].second << " " << last_blood[iter].first << "\n";
    ++ iter[0];
  }
  return 0;
}
