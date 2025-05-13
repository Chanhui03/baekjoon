#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int v, const vector<vector<int>> &arr, vector<bool> &visited, vector<int> &dfs_result) {
    visited[v] = true;
    dfs_result.push_back(v);

    for (int next : arr[v]) {
        if (!visited[next]) dfs(next, arr, visited, dfs_result);
    }
}

void bfs(int v, const vector<vector<int>> &arr, vector<bool> &visited, vector<int> &bfs_result) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        bfs_result.push_back(curr);

        for (int next : arr[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

// DFS와 BFS
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> arr(n + 1);
    vector<bool> visited_dfs(n + 1, false);
    vector<bool> visited_bfs(n + 1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // 오름차순 정렬: 방문 순서 보장
    for (int i = 1; i <= n; ++i) {
        sort(arr[i].begin(), arr[i].end());
    }

    vector<int> dfs_result, bfs_result;

    dfs(v, arr, visited_dfs, dfs_result);
    bfs(v, arr, visited_bfs, bfs_result);

    for (int x : dfs_result) cout << x << ' ';
    cout << '\n';
    for (int x : bfs_result) cout << x << ' ';
    cout << '\n';

    return 0;
}
