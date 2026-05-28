#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n  ; 
    cin >> x  ; 

    vector<int> hi(n);
    vector<int> si(n);

    for (int i = 0; i < n; ++i) {
        cin >> hi[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> si[i];
    }

    vector<long long> dp(x + 1, 0);

    for (int j = 0; j < n; ++j) {
        for (int i = x ; i >= hi[j] ; --i) {
            dp[i] = max(dp[i], dp[i - hi[j]] + si[j]);
        }
    }

    cout << dp[x] << endl;

    return 0;
}
