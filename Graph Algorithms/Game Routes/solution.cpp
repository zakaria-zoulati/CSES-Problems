#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1'000'000'007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0){
            q.push(i) ; 
        }
    }

    vector<int> dp(n + 1, 0);
    dp[1] = 1 ; 


    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : adj[node]) {
            dp[next] = (dp[next] + dp[node]) % MOD;
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}
