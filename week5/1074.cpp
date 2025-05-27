#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, count = 0;

void dc(int x, int y, int size) {
  if (c == x && r == y) {
    cout << count;
    return;
  }
  else if (c < x + size && r < y + size && c >= x && r >= y) {
    dc(x, y, size / 2);
    dc(x + size / 2, y, size / 2);
    dc(x, y + size / 2, size / 2);
    dc(x + size / 2, y + size / 2, size / 2);
  }
  else {
    count += size * size;
  }
}

// Z
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r >> c;

  dc(0, 0, pow(2, n));

  return 0;
}