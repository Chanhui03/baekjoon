#include <iostream>
#include <queue>

using namespace std;

int n, types, cnt[10], answer;
queue<int> q;

// 과일 탕후루
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    q.push(s);

    if (cnt[s]++ == 0) types++;

    while (types > 2) {
      s = q.front();
      q.pop();
      if (--cnt[s] == 0) types--;
    }

    answer = max(answer, static_cast<int>(q.size()));
  }

  cout << answer << '\n';

  return 0;
}