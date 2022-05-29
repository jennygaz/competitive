#include <iostream>

using namespace std;
constexpr int MAXN = 80;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  int balls[MAXN] {}, prizes[4] {};
  int corners[4] = {0, 4, 20, 24};
  int midline[5] = {10, 11, 12, 13, 14};
  int diagonals[9] = {0, 4, 6, 8, 12, 16, 18, 20, 24};
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, t {};
    int ticket[25] {};
    cin >> n >> t;
    for( int ball = 0; ball < n; ++ ball )
      cin >> balls[ball];
    for( int i = 0; i < 4; ++ i )
      cin >> prizes[i];
    cout << "Case " << CASE << ":\n";
    for( int i = 0; i < t; ++ i ){
      int curr_prize {};
      bool first {}, second {}, third {}, last {};
      bool used[25] {};
      for( int pos = 0; pos < 25; ++ pos )
	cin >> ticket[pos];
      for( int ball = 0; ball < n; ++ ball ){
	// Adjust the ball if found
	for( int pos = 0; pos < 25; ++ pos )
	  if( balls[ball] == ticket[pos] )
	    used[pos] = true;
	// check the prizes
	if( not first and ball < 35 ){ // corners
	  bool tmp = true;
	  for( int j = 0; tmp and j < 4; ++ j )
	    tmp = (tmp and used[corners[j]] );
	  first = tmp;
	}
	if( not second and ball < 40 ){ // midline
	  bool tmp = true;
	  for( int j = 0; tmp and j < 5; ++ j )
	    tmp = (tmp and used[midline[j]] );
	  second = tmp;
	}
	if( not third and ball < 45 ){ // diagonals
	  bool tmp = true;
	  for( int j = 0; tmp and j < 9; ++ j )
	    tmp = (tmp and used[diagonals[j]] );
	  third = tmp;
	}
	bool tmp = true;
	for( int j = 0; j < 25; ++ j ){ // full board
	  tmp = (tmp and used[j]);
	}
	last = tmp;
      }
      if( first ) curr_prize += prizes[0];
      if( second ) curr_prize += prizes[1];
      if( third ) curr_prize += prizes[2];
      if( last ) curr_prize += prizes[3];
      cout << curr_prize << '\n';
    }
    if( CASE != tc ) cout << '\n';
  }
  return 0;
}
