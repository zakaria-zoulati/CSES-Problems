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


    vector<int> dp(x + 1, 0);
    dp[0] = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=arr[i] ; j<=x ; ++j ){
            dp[j] = ( dp[j] + dp[ j - arr[i] ] ) % mod ; 
        }
    }

    cout << dp[x] << endl ; 
    return 0;
}
