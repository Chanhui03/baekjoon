#include <iostream>
#include <vector>
using namespace std;

// 상하좌우 탐색용
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// dfs
void dfs(int x, int y, vector<vector<int>> &v) {
  v[x][y] = 0;

  for (int n = 0; n < 4; n++) {
    int _x = x + dx[n];
    int _y = y + dy[n];
    // 아래 조건을 만족하면 재귀하며 연결된 부분들 0
    // 배추밭 크기 안에 있는 수 중에 v[_x][_y] 가 1을 찾았을 때 실행
    if (_x >= 0 && _x < v.size() &&
        _y >= 0 && _y < v[0].size() &&
        v[_x][_y] == 1) {
      dfs(_x, _y, v);
    }
  }
}

// 유기농 배추
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int test_case;
  cin >> test_case;

  while(test_case--) {
    int m, n, k; // m 가로 / n 세로
    cin >> m >> n >> k;
    vector<vector<int>> v(n, vector<int>(m,0));

    while(k--) {
      int a, b;
      // a 가로 / b 세로
      cin >> a >> b;
      v[b][a] = 1;
    }

    int count = 0;

    // i 세로 / j 가로
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 1) {
          count++;
          dfs(i, j, v);
        }
      }
    }
    cout << count << '\n';
  }

  return 0;
}