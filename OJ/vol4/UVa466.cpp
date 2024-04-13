/* Mirror, Mirror - UVa 466 */
/* by @jennygaz */
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

enum MatrixType {
  // use specific values for bitmasking
  PRESERVATION = 1,
  VERTICAL_MIRROR = 2,
  DEGREES_90 = 4,
  DEGREES_180 = 8,
  DEGREES_270 = 16,
  VERTICAL_90 = 32,
  VERTICAL_180 = 64,
  VERTICAL_270 = 128,
  NEITHER = 256
};

inline pair<int, int>
translate_to_rotation(int degrees, int x, int y, int dimension) {
  if( degrees == 90 ) {
    return { y, dimension - x - 1 };
  } else if( degrees == 180 ) {
    return { dimension - x - 1, dimension - y - 1 };    
  } else if( degrees == 270 ) {
    return { dimension - y - 1, x };
  } else return { x, y };
}

inline pair<int, int>
translate_to_mirror(int x, int y, int dimension) {
  return { dimension - x - 1, y };
}

MatrixType
check_matrix_for(
  vector<string>& from,
  vector<string>& to,
  int dimension
) {
  // check each type, fail early
  int bitmask = (int)(MatrixType::NEITHER) - 1; // start with all types matched
  int n = dimension;
  // check preservation, index 0 in the bitmask
  for( int x = 0; x < n and (bitmask & MatrixType::PRESERVATION); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::PRESERVATION); ++ y ) {
      if( from[x][y] != to[x][y] ) bitmask ^= MatrixType::PRESERVATION; // toggle off the preservation bit
    }
  }
  if( bitmask & MatrixType::PRESERVATION ) return MatrixType::PRESERVATION;

  // check for rotation 90 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::DEGREES_90); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::DEGREES_90); ++ y ) {
      auto translated = translate_to_rotation(90, x, y, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::DEGREES_90;
    }
  }
  if( bitmask & MatrixType::DEGREES_90 ) return MatrixType::DEGREES_90;

  // check for rotation 180 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::DEGREES_180); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::DEGREES_180); ++ y ) {
      auto translated = translate_to_rotation(180, x, y, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::DEGREES_180;
    }
  }
  if( bitmask & MatrixType::DEGREES_180 ) return MatrixType::DEGREES_180;

  // check for rotation 270 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::DEGREES_270); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::DEGREES_270); ++ y ) {
      auto translated = translate_to_rotation(270, x, y, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::DEGREES_270;
    }
  }
  if( bitmask & MatrixType::DEGREES_270 ) return MatrixType::DEGREES_270;

  // check vertical mirror
  for( int x = 0; x < n and (bitmask & MatrixType::VERTICAL_MIRROR); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::VERTICAL_MIRROR); ++ y ) {
      auto translated = translate_to_mirror(x, y, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::VERTICAL_MIRROR;
    }
  }
  if( bitmask & MatrixType::VERTICAL_MIRROR ) return MatrixType::VERTICAL_MIRROR;

  // check for composites, mirror + 90 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::VERTICAL_90); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::VERTICAL_90); ++ y ) {
      auto translated = translate_to_mirror(x, y, n);
      translated = translate_to_rotation(90, translated.first, translated.second, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::VERTICAL_90;
    }
  }
  if( bitmask & MatrixType::VERTICAL_90 ) return MatrixType::VERTICAL_90;

  // check for composites, mirror + 180 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::VERTICAL_180); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::VERTICAL_180); ++ y ) {
      auto translated = translate_to_mirror(x, y, n);
      translated = translate_to_rotation(180, translated.first, translated.second, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::VERTICAL_180;
    }
  }
  if( bitmask & MatrixType::VERTICAL_180 ) return MatrixType::VERTICAL_180;

  // check for composites, mirror + 270 degrees
  for( int x = 0; x < n and (bitmask & MatrixType::VERTICAL_270); ++ x ) {
    for( int y = 0; y < n and (bitmask & MatrixType::VERTICAL_270); ++ y ) {
      auto translated = translate_to_mirror(x, y, n);
      translated = translate_to_rotation(270, translated.first, translated.second, n);
      if( from[x][y] != to[translated.first][translated.second] ) bitmask ^= MatrixType::VERTICAL_270;
    }
  }
  if( bitmask & MatrixType::VERTICAL_270 ) return MatrixType::VERTICAL_270;

  return MatrixType::NEITHER;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int len {}, tc {};
  vector<string> lhs(11), rhs(11);
  while( cin >> len ) {
    for( int i = 0; i < len; ++ i )
      cin >> lhs[i] >> rhs[i];
    MatrixType result = check_matrix_for( lhs, rhs, len );
    cout << "Pattern " << (++ tc) << " was ";
    switch( result ) {
    case PRESERVATION: cout << "preserved.\n";
      break;
    case VERTICAL_MIRROR: cout << "reflected vertically.\n";
      break;
    case DEGREES_90: cout << "rotated 90 degrees.\n";
      break;
    case DEGREES_180: cout << "rotated 180 degrees.\n";
      break;
    case DEGREES_270: cout << "rotated 270 degrees.\n";
      break;
    case VERTICAL_90: cout << "reflected vertically and rotated 90 degrees.\n";
      break;
    case VERTICAL_180: cout << "reflected vertically and rotated 180 degrees.\n";
      break;
    case VERTICAL_270: cout << "reflected vertically and rotated 270 degrees.\n";
      break;
    case NEITHER:
    default:
      cout << "improperly transformed.\n";
    }
  }
  return 0;
}
