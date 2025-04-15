#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, temp_i;
  string temp_s;
  multimap<int, string> input_list;
  multimap<int, string> ::iterator iter;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> temp_i >> temp_s;
    input_list.insert({temp_i, temp_s});
  }

  for(iter = input_list.begin(); iter != input_list.end(); iter++) {
    cout << iter->first << ' ' << iter->second << endl;
  }

  return 0;
}