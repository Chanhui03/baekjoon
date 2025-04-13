#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K; //n,k입력받기

    queue<int> q; //큐 자료형 q 생성
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        vector<int> selected;

        int count = min(K, (int)q.size());
        for (int i = 0; i < count; i++) {
            selected.push_back(q.front());
            q.pop();
        }

        q.push(selected[0]);
    }

    cout << q.front();
    return 0;
}
