#include <iostream>
#include <string>

using namespace std;

// 문자열 반복
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t, r;
  string s;

  cin >> t;
  while(t--) {
    cin >> r;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < r; j++) {
        cout << s[i];
      }
    }
    cout << '\n';
  }

  return 0;
}