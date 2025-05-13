#include <iostream>
#include <string>
using namespace std;

// 잃어버린 괄호
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  cin >> input;

  int result = 0;
  string num;
  bool isMinus = false; // 첫 마이너스 뒤는 모두 괄호

  for (int i = 0; i <= input.size(); i++) {
    if (input[i] == '-' || input[i] == '+' || i == input.size()) {
      if (isMinus) {
        result -= stoi(num);
        num = "";
      }
      else {
        result += stoi(num);
        num = "";
      }
    }
    else {
      num += input[i];
    }

    if (input[i] == '-') isMinus = true;
  }

  cout << result;

  return 0;
}