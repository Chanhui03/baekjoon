#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> arr;
priority_queue<int> q;

// 최대 힙
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      if (q.empty()) {
        arr.push_back(0);
        continue;
      }
      arr.push_back(q.top());
      q.pop();
      continue;
    }
    q.push(x);
  }

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << '\n';
  }

  return 0;
}