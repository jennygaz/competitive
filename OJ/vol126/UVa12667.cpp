/* Last Blood - UVa 12667 */
/* by @jennygaz */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// Collect the teams' data, store it as a map problem[team -> time]
// then just invert each container, sort it by time, print the time and team

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int problems {}, teams {}, queries {};
  int time {}, team_id {};
  string problem {}, verdict {};
  cin >> problems >> teams >> queries;
  vector<map<int, pair<int, int>>> cont(teams + 1); // initialize teams + 1 hash_maps
  while( queries -- ) {
    cin >> time >> team_id >> problem >> verdict;
    if( verdict[0] == 'N' ) continue;
    if( problem[0] - 'A' >= problems ) continue;
    if( cont[problem[0] - 'A'].find( team_id ) == cont[problem[0] - 'A'].end() )
      cont[problem[0] - 'A'][team_id] = make_pair(queries, time);
  }
  for( int i = 0; i < problems; ++ i ) {
    cout << (char)('A' + i) << " ";
    if( cont[i].size() == 0 ) cout << "- -\n";
    else {
      vector<pair<int, pair<int, int>>> subcont(cont[i].begin(), cont[i].end());
      sort(
        subcont.begin(),
        subcont.end(),
          []( pair<int, pair<int, int>>& lhs, pair<int, pair<int, int>>& rhs ) -> bool {
            int a = lhs.first, b = lhs.second.first, c = lhs.second.second;
            int d = rhs.first, e = rhs.second.first, f = rhs.second.second;
            return (c != f ? c < f : (b != e ? b > e : a < d));
      });
      auto last_blood = *subcont.rbegin();
      cout << last_blood.second.second << " " << last_blood.first << '\n';
    }
  }
  return 0;
}
