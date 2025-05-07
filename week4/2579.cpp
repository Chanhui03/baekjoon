#include <iostream>
#include <algorithm>
using namespace std;

//dp
//Bottom-up 방식
//score[n] = score[n - 2] + stair[n]
//score[n] = score[n - 3] + stair[n - 1] + stair[n]
int main() {
  int n;
  int stair[301], score[301]; //계단 수, 계산 횟수
  cin >> n;

  for (int i = 1; i <= n; i++) cin >> stair[i];

  score[1] = stair[1]; //1일때
  score[2] = stair[1] + stair[2];//2일때
  score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);//3일때

  for (int i = 4; i <= n; i++) {
    int a = score[i - 2] + stair[i];
    int b = score[i - 3] + stair[i - 1] + stair[i];
    score[i] = max(a, b);
  }

  cout << score[n];
  return 0;
}