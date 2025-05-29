#include <iostream>

using namespace std;

// 검증수
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int temp, sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> temp;
    sum += (temp * temp);
  }

  cout << sum % 10;

  return 0;
}