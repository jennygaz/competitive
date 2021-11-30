#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
inline int find_min_from_to( vector<int>& cont, int dist, int from ){
  int idx = -1, min_val = 1000100;
  int max_it = min( (int)cont.size(), from + dist );
  for( int i = from; i <= max_it; ++ i ){
    if( cont[i] < min_val ){
      idx = i;
      min_val = cont[i];
    }
    -- dist;
  }
  return idx;
}

vector <int> findMinArray(vector <int> arr, int k) {
  for( int i = 0; k > 0 and i < (int)arr.size(); ++ i ){
    cerr << "calling find_min_from_to( arr, " << k << ", " << i << " )" << endl;
    int min_idx = find_min_from_to( arr, k, i );
    cerr << "min_idx: " << min_idx << endl;
    if( min_idx == i ) continue;
    k -= min_idx - i;
    cerr << "k: " << k << endl;
    while( min_idx > i ){
      cerr << "Swapping: ( " << arr[min_idx] << ", " << arr[min_idx - 1] << " )" << endl;
      swap( arr[min_idx], arr[min_idx - 1] );
      -- min_idx;
    }
  }
  return arr;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  int n_1 = 3, k_1 = 2;
  vector <int> arr_1{5, 3, 1};
  vector <int> expected_1{1, 5, 3};
  vector <int> output_1 = findMinArray(arr_1,k_1);
  check(expected_1, output_1);

  int n_2 = 5, k_2 = 3;
  vector <int> arr_2{8, 9 ,11, 2, 1};
  vector <int> expected_2{2, 8, 9, 11, 1};
  vector <int> output_2 = findMinArray(arr_2,k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
