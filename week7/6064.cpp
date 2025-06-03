#include <iostream>

using namespace std;

// 카잉 달력
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t, m, n;
  int x, y;

  cin >> t;

  while (t--) {
    cin >> m >> n >> x >> y;
    while (true) {
      if (x == y) {
        cout << x << '\n';
        break;
      }
      else if (x > m * n) {
        cout << -1 << '\n';
        break;
      }

      if (x < y) x += m;
      else y += n;
    }
  }

  return 0;
}