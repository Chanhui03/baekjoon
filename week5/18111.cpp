#include <iostream>

using namespace std;

int n, m, b;
int land[504][504];
int min_t = 99999999, min_h = 99999999;


// 마인크래프트
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m >> b;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> land[i][j];
    }
  }

  int time; // 시간 체크용

  for (int h = 0; h <= 256; h++) {
    int remove = 0;
    int stack = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (land[i][j] > h) {
          remove += land[i][j] - h;
        }
        else if (land[i][j] == h) {
          continue;
        }
        else if (land[i][j] < h) {
          stack += h - land[i][j];
        }
      }
    }

    if (remove + b >= stack) {
      time = remove * 2 + stack;
      if (time <= min_t) {
        min_t = time;
        min_h = h;
      }
    }
  }
  
  cout << min_t << ' ' << min_h << '\n';

  return 0;
}