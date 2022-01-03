/* UVa 466 - Mirror, Mirror */
/* Solution: Check the patterns in order */
/* * Preservation
 * * Rotation (pi/2, pi, 3pi/2)
 * * Vert. Reflection
 * * Vert. Reflection + Rotation
 * * Neither
 */
/* by jennyga */

#include <iostream>
#include <string>

using namespace std;

constexpr int MAXDIM = 11;

bool check_rotation( string * lhs, string * rhs, int deg = 0 ){
  int DIM = (int)lhs[0].length();
  for( int row = 0; row < DIM; ++ row ){
    for( int col = 0; col < DIM; ++ col ){
      int rhs_row {row}, rhs_col {col};
      if( deg == 90 ){
	rhs_row = col;
	rhs_col = DIM - row - 1;
      }
      else if( deg == 180 ){
	rhs_row = DIM - row - 1;
	rhs_col = DIM - col - 1;
      }
      else if( deg == 270 ){
	rhs_row = DIM - col - 1;
	rhs_col = row;
      }
      if( lhs[row][col] != rhs[rhs_row][rhs_col] )
	return false;
    }
  }
  return true;
}

bool check_mirror( string * lhs, string * rhs ){
  int DIM = (int)lhs[0].length();
  for( int row = 0; row < DIM; ++ row ){
    for( int col = 0; col < DIM; ++ col ){
      int rhs_row {DIM - row - 1}, rhs_col {col};
      if( lhs[row][col] != rhs[rhs_row][rhs_col] )
	return false;
    }
  }
  return true;
}

// Just use the previous functionality but changing the indexes
bool check_composite( string * lhs, string * rhs, int deg = 0 ){
  int DIM = (int)lhs[0].length();
  for( int row = 0; row < DIM; ++ row ){
    for( int col = 0; col < DIM; ++ col ){
      int rhs_row {DIM - row - 1}, rhs_col {col};
      if( deg == 270 ){
	rhs_row = DIM - col - 1;
	rhs_col = DIM - row - 1;
      }
      else if( deg == 180 ){
	rhs_row = DIM - row - 1;
	rhs_col = col;
      }
      else if( deg == 90 ){
	rhs_row = col;
	rhs_col = row;
      }
      if( lhs[row][col] != rhs[rhs_row][rhs_col] )
	return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  void init_xy();
  string lhs[MAXDIM] {}, rhs[MAXDIM] {};
  int DIM {}, PATTERN {};
  while( cin >> DIM ){
    // read patterns
    for( int i = 0; i < DIM; ++ i )
      cin >> lhs[i] >> rhs[i];
    // Initialize the messages
    const string msg[9] = {
      "preserved.\n",                                       // 0 
      "rotated 90 degrees.\n",                              // 1  
      "rotated 180 degrees.\n",                             // 2
      "rotated 270 degrees.\n",                             // 3
      "reflected vertically.\n",                            // 4
      "reflected vertically and rotated 90 degrees.\n",     // 5
      "reflected vertically and rotated 180 degrees.\n",    // 6
      "reflected vertically and rotated 270 degrees.\n",    // 7
      "improperly transformed.\n"                           // 8 
    };
    int ans {8};
    // Check them in order
    
    if( check_rotation( lhs, rhs, 0 ) ) ans = 0;
    else if( check_rotation( lhs, rhs, 90 ) ) ans = 1;
    else if( check_rotation( lhs, rhs, 180 ) ) ans = 2;
    else if( check_rotation( lhs, rhs, 270 ) ) ans = 3;
    else{
      for( int row = 0; row < DIM / 2; ++ row ){
	for( int col = 0; col < DIM; ++ col ){
	  char tmp = rhs[row][col];
	  rhs[row][col] = rhs[DIM - row - 1][col];
	  rhs[DIM - row - 1][col] = tmp;
	}
      }
      if( check_rotation( lhs, rhs, 0 ) ) ans = 4;
      else if( check_rotation( lhs, rhs, 270 ) ) ans = 5;
      else if( check_rotation( lhs, rhs, 180 ) ) ans = 6;
      else if( check_rotation( lhs, rhs, 90 ) ) ans = 7;
      else ans = 8;
    }
    cout << "Pattern " << ++PATTERN << " was " << msg[ans];
  }
  return 0;
}
