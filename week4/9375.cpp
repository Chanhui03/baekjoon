#include <iostream>
#include <string>
#include <map>

using namespace std;

//패션왕 신해빈
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case, n; 
  string category, temp_name;
  cin >> test_case; // 처음 입력값 케이스 반복 횟수

  while (test_case--) {
    map<string, int> m; // key값은 카테고리
    cin >> n; // 입력 받을 옷 개수
    while (n--) {
      // temp_name은 사용하지 않음
      cin >> temp_name >> category;
      if (m.find(category) == m.end()) m.insert({category, 1});
      else m[category]++;
    }

    int ans = 1;
    for (auto i : m) {
      ans *= (i.second + 1);
    }
    ans -= 1;
    cout << ans << '\n';
  }

  return 0;
}
