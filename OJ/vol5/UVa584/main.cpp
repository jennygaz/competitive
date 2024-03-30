// UVa 584 - Bowling
// Jenny Gallegos

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline int value_of(char c) {
  return (c == 'X' ? 10 : c == '/' ? 10 : c - '0');
}

int compute_score(vector<string>& frames) {
  int score {}, num_frames {};
  for( int i = 0; num_frames < 20; ++ i ) {
    if( frames[i][0] == 'X' ) {
      if( i + 2 < frames.size() and frames[i + 2][0] == '/' ) score += 20;
      else score += 10 + value_of(frames[i + 1][0]) + value_of(frames[i + 2][0]);
      ++ num_frames; ++ num_frames;
    } else if( frames[i][0] == '/' ) {
      score += 10 - value_of(frames[i - 1][0]) + value_of(frames[i + 1][0]);
      ++ num_frames;
    } else {
      score += value_of(frames[i][0]);
      ++ num_frames;
    }
  }
  return score;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  vector<string> frames {};
  while( getline( cin, line ), line[0] != 'G' ) {
    istringstream iss(line);
    string token {};
    while( iss >> token ) frames.emplace_back(token);
    int ans = compute_score(frames);
    cout << ans << '\n';
    frames.clear();
  }
  return 0;
}
