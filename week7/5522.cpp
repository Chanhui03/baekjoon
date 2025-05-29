#include <iostream>

using namespace std;

// 카드 게임
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int temp, sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> temp;
    sum += temp;
  }

  cout << sum;

  return 0;
}