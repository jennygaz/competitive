#include <iostream>

using namespace std;

void bst( int lhs, int rhs, int height ){
  if( height == 0 or lhs > rhs ) return;
  int right_subtree = ((1 << (height - 1)) - 1);
  int root = rhs - right_subtree;
  if( root < lhs ) root = lhs;
  cout << " " << root;
  bst( lhs, root - 1, height - 1 );
  bst( root + 1, rhs, height - 1 );
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n {}, height {}, CASE {};
  while( cin >> n >> height, n | height ){
    cout << "Case " << ++CASE << ":";
    if( ((1 << height) - 1) < n ){
      cout << " Impossible.\n";
      continue;
    }
    if( height > n ) height = n;
    bst( 1, n, height );
    cout << '\n';
  }
  return 0;
}

