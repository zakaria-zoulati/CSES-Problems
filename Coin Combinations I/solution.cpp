#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 1e9 + 7;
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 

    sort( arr.begin() , arr.end() ) ; 

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if(  arr[j] > i ) break ; 
            dp[i] = (dp[i] + dp[i - arr[j]]) % mod;
        }
    }
    cout << dp[x] << endl ; 
    return 0;
}
