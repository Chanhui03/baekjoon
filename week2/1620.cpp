#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> //map 사용 unordered_map 사용 시 해시 기반 탐색이므로 O(1)이 됨

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  string buf; //이름 버퍼
  vector<string> num_find(1); //번호로 찾을 도감

  unordered_map<string, int> string_find; //문자열로 찾을 도감

  for(int i = 1; i <= n; i++) {
    cin >> buf;
    string_find.insert({ buf, i});
    num_find.push_back(buf);
  }

  for(int i = 1; i <= m; i++) {
    cin >> buf;
    isdigit(buf[0]) ? cout << num_find[stoi(buf)] << '\n' : cout << string_find.find(buf)->second << '\n';
    //map에서 2번째 인자인 second 출력
  }


  return 0;
}