#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, vector<vector<int>> &v, vector<vector<int>> &v_result) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  v[x][y] = 0;
  v_result[x][y] = 0;

  while (!q.empty()) {
    int curr_x = q.front().first;
    int curr_y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int new_x = curr_x + dx[i];
      int new_y = curr_y + dy[i];
      if (new_x >= 0 && new_x < v.size() && new_y >= 0 && new_y < v[0].size() && v[new_x][new_y] == 1) {
        q.push(make_pair(new_x, new_y));
        v[new_x][new_y] = 0;
        v_result[new_x][new_y] = v_result[curr_x][curr_y] + 1;
      }
    }
  }
}

// 쉬운 최단거리
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  vector<vector<int>> v_result(n, vector<int>(m, -1));
  
  int ix, iy;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int temp;
      cin >> temp;
      if (temp == 2) {ix = i; iy = j;}
      else if (temp == 0) v_result[i][j] = 0;
      v[i][j] = temp;
    }
  }

  bfs(ix, iy, v, v_result);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << v_result[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}