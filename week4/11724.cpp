#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

//연결 요소의 개수
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // 1-indexed
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 무방향 그래프
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }

    cout << components << '\n';
    return 0;
}
