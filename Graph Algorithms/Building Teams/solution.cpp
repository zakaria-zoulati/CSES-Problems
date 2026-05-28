#include <bits/stdc++.h>
using namespace std;

// DFS function for Bipartite Check
bool dfs(int node, vector<int>& groups, const vector<vector<int>>& graph) {
    for (int child : graph[node]) {
        if (groups[child] == 0) {
            groups[child] = 3 - groups[node]; // Assign to the opposite group
            if (!dfs(child, groups, graph)) {
                return false;
            }
        } else if (groups[child] == groups[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> groups(n + 1, 0);

    // Check all components
    for (int i = 1; i <= n; ++i) {
        if (groups[i] == 0) {
            groups[i] = 1;
            if (!dfs(i, groups, graph)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // Print groups of every node
    for (int i = 1; i <= n; ++i) {
        cout << groups[i] << " ";
    }
    cout << "\n";

    return 0;
}