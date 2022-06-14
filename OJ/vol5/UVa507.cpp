#include <iostream>

using namespace std;
constexpr int MAXN = 20020;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  cin >> tc;
  for( int CASE = 1; CASE <= tc; ++ CASE ){
    int n {}, val {};
    cin >> n;
    int tmp = 1, left_idx = 0xffff, right_idx {}, sum {}, ans {};
    for( int i = 2; i <= n; ++ i ){
      cin >> val;
      sum += val;
      if( sum < 0 ){
	sum = 0;
	tmp = i;
      }
      if( sum >= ans ){
	if( sum > ans or (sum == ans and (i - tmp > right_idx - left_idx))){
	  left_idx = tmp;
	  right_idx = i;
	}
	ans = sum;
      }
    }
    if( ans > 0 )
      cout << "The nicest part of route " << CASE << " is between stops " << left_idx << " and " << right_idx << '\n';
    else
      cout << "Route " << CASE << " has no nice parts\n";
  }
  return 0;
}
