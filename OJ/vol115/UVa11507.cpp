/* UVa 11507 - Bender B. Rodriguez Problem */
/* Solution: Just change the direction on certain cases */
/* by jennyga */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

constexpr int XPOS = 1, XNEG = 4, YPOS = 2, YNEG = 5, ZPOS = 3, ZNEG = 6;

// small hashmap to store the operations for quick access
int bend[10][10] {};
string ans[10] {};
// create the operations at the start
inline void fill_bend(){
  // +/- X plus +/- y
  bend[XPOS][YPOS] = YPOS;
  bend[XNEG][YPOS] = YNEG;
  bend[XPOS][YNEG] = YNEG;
  bend[XNEG][YNEG] = YPOS;

  // +/- Z plus +/- Y
  bend[ZPOS][YPOS] = ZPOS;
  bend[ZNEG][YPOS] = ZNEG;
  bend[ZPOS][YNEG] = ZPOS;
  bend[ZNEG][YNEG] = ZNEG;

  // +/- Y plus +/- Y
  bend[YPOS][YPOS] = XNEG;
  bend[YNEG][YPOS] = XPOS;
  bend[YPOS][YNEG] = XPOS;
  bend[YNEG][YNEG] = XNEG;

  // +/- X plus +/- Z
  bend[XPOS][ZPOS] = ZPOS;
  bend[XNEG][ZPOS] = ZNEG;
  bend[XPOS][ZNEG] = ZNEG;
  bend[XNEG][ZNEG] = ZPOS;

  // +/- Z plus +/- Z
  bend[ZPOS][ZPOS] = XNEG;
  bend[ZNEG][ZPOS] = XPOS;
  bend[ZPOS][ZNEG] = XPOS;
  bend[ZNEG][ZNEG] = XNEG;

  // +/- Y plus +/- Z
  bend[YPOS][ZPOS] = YPOS;
  bend[YNEG][ZPOS] = YNEG;
  bend[YPOS][ZNEG] = YPOS;
  bend[YNEG][ZNEG] = YNEG;
}

// function to fill the values at the out hashmap
inline void fill_ans(){
  ans[XPOS] = "+x";
  ans[XNEG] = "-x";
  ans[YPOS] = "+y";
  ans[YNEG] = "-y";
  ans[ZPOS] = "+z";
  ans[ZNEG] = "-z";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fill_bend();
  fill_ans();
  int len {};
  string line {};
  while( cin >> len, len ){
    int dir = XPOS, step {};
    while( -- len ){
      cin >> line;
      if( line[1] == 'o' ) continue;
      step = line[1] - 'x' + 1 + (line[0] - '+') * 1.5;
      dir = bend[dir][step];
    }
    cout << ans[dir] << '\n';
  }
  return 0;
}
