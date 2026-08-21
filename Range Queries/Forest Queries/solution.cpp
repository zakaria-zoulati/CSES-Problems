#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n , q ; 
    cin >> n >> q ; 
    
    vector<string> grid(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> grid[i];  
    }

    vector<vector<int>> dp( n+2 , vector<int>(n+2,0) ) ; 
    for( int i=1 ; i<=n ; ++i ){
        int curr = 0 ; 
        for( int j=1 ; j<=n ; ++j ){
            if( grid[i-1][j-1] == '*' ){
                curr++ ;
            } 
            dp[i][j] += curr ; 
            dp[i+1][j] = dp[i][j];
        }
    }

    while( q-- ){
        int y1 , x1 ;
        cin >> x1 >> y1 ; 
        int y2 , x2 ; 
        cin >> x2 >> y2 ; 

        int ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] ; 
        cout << ans << '\n' ; 
    }
}   

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}