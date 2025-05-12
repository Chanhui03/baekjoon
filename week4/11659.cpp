#include <iostream>
#include <vector>
using namespace std;

//구간 합 구하기 4
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    v[i] = v[i - 1] + temp;
  }

  while(m--) {
    int i, j;
    cin >> i >> j;
    cout << v[j] - v[i - 1] << '\n';
  }

  return 0;
}