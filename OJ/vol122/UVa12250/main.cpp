// UVa 12250 - Language Detection

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_map<string, string> lang{ {"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"} };
  int tc {1};
  string line {};
  getline( cin, line );
  while( line != "#" ){
    cout << "Case " << tc ++ << ": ";
    if( lang.find( line ) == lang.end() )
      cout << "UNKNOWN\n";
    else
      cout << lang[line] << '\n';
    getline( cin, line );
  }
  return 0;
}
