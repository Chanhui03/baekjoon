#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, temp, sum = 0;
  cin >> n;
  vector<int> pi;

  for(int i = 0; i < n; i++) {
    cin >> temp;
    pi.push_back(temp);
  }

  sort(pi.begin(),pi.end());

  for(auto i : pi) {
    static int j = n;
    sum += i*j;
    j--;
  }

  cout << sum << '\n';

  return 0;
}