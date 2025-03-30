#include <iostream> 
#include <vector> 

using namespace std ; 

int main(){
    int n , m ; 
    cin >> n >> m ; 
    vector< vector<int>> dp( n+1 , vector<int>(m+1) ) ; 
    
    for( int i=1 ; i<=n ; ++i ){
        dp[i][1] = i-1 ; 
    }
    for( int i=1 ; i<=m ; ++i ){
        dp[1][i] = i-1 ; 
    }

    for( int i=2 ; i<=n ; ++i ){
        for( int j=2 ; j<=m ; ++j ){
            if( i == j ){
                dp[i][j] = 0 ; 
                continue ; 
            }
            dp[i][j] = 1e9 ; 
            // Try the vertical cuts 
            for( int k=1 ; k < i ; ++k ){
                dp[i][j] = min( dp[i][j] ,  dp[k][j] + dp[i-k][j] + 1 ) ; 
            }
            // Try the horizontal cuts 
            for( int k=1 ; k< j ; ++k ){
                dp[i][j] = min( dp[i][j] ,  dp[i][k] + dp[i][j-k] + 1 ) ; 
            }
        }
    }


    cout << dp[n][m] << endl ; 
    return 0 ; 
}