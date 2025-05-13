#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int pcount = 0;

void dfs(int x, int y, vector<vector<char>> &arr) {
  arr[x][y] = 'X';
  for (int n = 0; n < 4; n++) {
    int _x = x + dx[n];
    int _y = y + dy[n];
    if (_x >= 0 && _x < arr.size() &&
        _y >= 0 && _y < arr[0].size() &&
        arr[_x][_y] != 'X') {
          if (arr[_x][_y] == 'P') pcount++;
          dfs(_x, _y, arr);
      }
  }
}

// 헌내기는 친구가 필요해
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<char>> v(n, vector<char>(m));
  
  int ix, iy;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char temp;
      cin >> temp;
      if (temp == 'I') {ix = i; iy = j;}
      v[i][j] = temp; // v[i][j] = temp;
    }
  }

  dfs(ix, iy, v);
  
  (pcount != 0) ? cout << pcount : cout << 'T' << 'T'; 

  return 0;
}