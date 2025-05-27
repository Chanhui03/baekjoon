#include <iostream>
using namespace std;

int arr[129][129]; // 최대 종이 길이
int white = 0; // 흰 종이
int blue = 0; // 파란 종이

void isCut(int x, int y, int k) {
  bool cut = false; // cut 유무
  int first_color = arr[x][y]; // 첫 번째 칸의 색
  for (int i = x; i < x + k; i++) {
    for (int j = y; j < y + k; j++) {
      if (arr[i][j] != first_color) { // 다른 색이 나올 시 자르기
        cut = true;
        break;
      }
    }
  }
  if (cut) { // 잘라야할 때 재귀
    // 4 부분 다 검사
    isCut(x, y, k / 2);
    isCut(x, y + k / 2, k / 2);
    isCut(x + k / 2, y, k / 2);
    isCut(x + k / 2, y + k / 2, k / 2);
  }
  else {
    if (first_color == 1) blue++; // 파란 종이
    else white++; // 흰 종이
  }
}

// 색종이 만들기
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  isCut(0, 0, n);
  
  cout << white << '\n';
  cout << blue << '\n';

  return 0;
}

