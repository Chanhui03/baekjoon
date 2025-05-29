#include <iostream>
#include <string>

using namespace std;

// 숫자의 합
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, sum = 0;
  string s;
  cin >> n;
  cin >> s;

  for (int  i = 0; i < n; i++) {
    sum += s[i] - '0';
  }

  cout << sum;

  return 0;
}