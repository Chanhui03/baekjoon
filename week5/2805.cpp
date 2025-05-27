#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 나무의 개수, 가져가려고 하는 나무의 길이
vector<int> tree; //현재 나무의 높이 저장용 배열

// 나무 자르기
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x; // 나무들의 높이
    tree.push_back(x);
  }

  int start = 0;
  int end = *max_element(tree.begin(), tree.end());
  int result = 0;

  while (start <= end) {
    long long int total = 0;
    int mid = (start + end) / 2;
    for (int i = 0; i < n; i++) {
      if (tree[i] > mid) total += tree[i] - mid;
    }
    if (total < m) {
      end = mid - 1;
    }
    else {
      result = mid;
      start = mid + 1;
    }
  }

  cout << result << '\n';

  return 0;
}