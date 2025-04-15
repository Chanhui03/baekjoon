#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> non_h, non_s, non_hs;
  
  for(int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if(find(non_h.begin(), non_h.end(), temp) == non_h.end()) non_h.push_back(temp);
    else return 0;
  }

  for(int i = 0; i < m; i++) {
    string temp;
    cin >> temp;
    if(find(non_s.begin(), non_s.end(), temp) == non_h.end()) non_s.push_back(temp);
    else return 0;
  }

  for(int i = 0; i < non_h.size(); i++) {
    for( int j = 0; j < non_s.size();) {
      if(non_h[i] == non_s[j]) non_hs.push_back(non_h[i]);
    }
  }

  sort(non_hs.begin(), non_hs.end(), greater<string>());
  cout << non_hs.size() << '\n';
  for(int i = 0; i < non_hs.size(); i++) cout << non_hs[i] << '\n';

  return 0;
}