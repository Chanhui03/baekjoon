#include <iostream>
#include <vector>
#include <algorithm> //정렬 함수가 포함된 라이브러리

using namespace std;

int adding(vector<int>& arr, int M);

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> arr(N);
  for(int i = 0; i < N; i++) cin >> arr[i];

  int count = adding(arr, M);
  cout << count << endl;

  return 0;
}

int adding(vector<int>& arr, int M) {
  sort(arr.begin(), arr.end());

  int left = 0;
  int right = arr.size() - 1;
  int count = 0;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == M) {
      count++;
      left++;
      right--;
    } else if (sum < M) {
      left++;
    } else {
      right--;
    }
  }

  return count;
}

//투 포인터 알고리즘을 사용하려면 정렬이 필수
