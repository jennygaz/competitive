#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int start_val = 11, end_val = 99999999;
  vector<int> runaround {};
  for( int curr_val = start_val; curr_val <= end_val; ++ curr_val ){
    string values = to_string( curr_val );
    int used = 0;
    bool cont = false;
    for( int i = 0; not cont and i < (int)values.size(); ++ i ){
      if( values[i] == '0' ) cont = true;
      if( used & (1 << (values[i] - '0')) ) cont = true;
      used |= (1 << (values[i] - '0'));
    }
    if( cont ) continue;
    int bitmask {};
    int curr_idx = 0, offset = values[0] - '0';
    for( int i = 0; i < (int)values.size(); ++ i ){
      curr_idx += offset;
      curr_idx %= values.size();
      bitmask |= (1 << curr_idx);
      offset = values[curr_idx] - '0';
    }
    if( __builtin_popcount( bitmask ) == values.size() )
      runaround.emplace_back( curr_val );
  }
  cout << "{ ";
  for( auto& run : runaround )
    cout << run << ',';
  cout << " }\n";
  return 0;
}
