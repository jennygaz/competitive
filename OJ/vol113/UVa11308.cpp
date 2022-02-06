/* UVa 11308 - Bankrupt Baker */
/* Solution: use a hashmap for the ingredients and similar, add the valid strings to a vector and input them in sorted order */
/* by jennyga */

#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <utility>
#include <functional>

using namespace std;

constexpr int MAX_RECIPES = 110;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  string line {};
  getline( cin, line );
  tc = stoi( line );
  tuple<int, string> recipes[MAX_RECIPES] {};
  while( tc -- ){
    int ingredients_no {}, recipes_no {}, budget {}, tmp {}, valid_idx {};
    string case_name {}, ing_name {}, recipe_name {};
    unordered_map<string, int> ingredients {};
    getline( cin, case_name );
    getline( cin, line );
    istringstream case_parser( line );
    case_parser >> ingredients_no >> recipes_no >> budget;
    // Uppercase
    for( int i = 0; i < (int)case_name.length(); ++ i )
      if( 'a' <= case_name[i] and case_name[i] <= 'z' )
	case_name[i] = 'A' + (case_name[i] - 'a');
    // Get ingredients' costs
    for( int i = 0; i < ingredients_no; ++ i ){
      getline( cin, line );
      istringstream iss( line );
      iss >> ing_name >> tmp;
      ingredients[ing_name] = tmp;
    }
    // process recipes
    for( int i = 0; i < recipes_no; ++ i ){
      int total {};
      getline( cin, recipe_name );
      getline( cin, line );
      istringstream recipe_parser( line );
      recipe_parser >> ingredients_no;
      for( int j = 0; j < ingredients_no; ++ j ){
	getline( cin, line );
	istringstream iss( line );
	iss >> ing_name >> tmp;
	total += tmp * ingredients[ing_name];
      }
      if( total <= budget )
	recipes[valid_idx ++] = { total, recipe_name };
    }
    sort( recipes, recipes + valid_idx );
    cout << case_name << '\n';
    if( valid_idx )
      for( int i = 0; i < valid_idx; ++ i )
	cout << get<1>( recipes[i] ) << '\n';
    else
      cout << "Too expensive!\n";
    cout << '\n';
  }
  return 0;
}
