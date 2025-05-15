#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int &a : arr) cin >> a;

    int N = 1 << n;
    vector<pair<int, int>> dp(N, {n + 1, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < N; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                int next_mask = mask | (1 << i);
                auto [groups, curr_weight] = dp[mask];
                if (curr_weight + arr[i] <= x) {
                    dp[next_mask] = min(dp[next_mask], {groups, curr_weight + arr[i]});
                } else {
                    dp[next_mask] = min(dp[next_mask], {groups + 1, arr[i]});
                }
            }
        }
    }

    cout << dp[N - 1].first << endl;
    return 0;
}
