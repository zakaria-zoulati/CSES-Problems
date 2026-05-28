#include <iostream> 
#include <vector>

using namespace std ; 

using ll = long long ; 

int main(){
    string s , t ; 
    cin >> s >> t ; 
    int n = s.size() ; 
    int m = t.size() ; 
    vector<vector<int>> dp( n+1 , vector<int>(m+1,0) ) ; 
    for( int i=0 ; i<=m ; ++i ){
        dp[0][i] = i ; 
    }
    for( int i=0 ; i<=n ; ++i ){
        dp[i][0] = i ; 
    }

    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
           if( s[i-1] == t[j-1] ){
              dp[i][j] = dp[i-1][j-1] ; 
           }else {
              dp[i][j] = 9999999 ; 
              dp[i][j] = min( dp[i][j] , 1 + dp[i-1][j-1] ) ; 
              dp[i][j] = min( dp[i][j] , 1 + dp[i][j-1] ) ; 
              dp[i][j] = min( dp[i][j] , 1 + dp[i-1][j] ) ; 
           }
        }
    }
    
   
    cout << dp[n][m] << endl ; 
    return 0 ; 
}