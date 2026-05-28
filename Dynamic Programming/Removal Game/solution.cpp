#include <iostream> 
#include <vector>
#include <climits>

using namespace std ; 

using ll = long long ; 


int main() {
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ) cin >> arr[i] ; 
    vector< ll > prefix( n ) ; 
    prefix[0] = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        prefix[i] = prefix[i-1] + arr[i] ; 
    }
    vector< vector<ll> > dp( n , vector<ll>(n, LONG_MIN )) ; 
    for( int i=0; i<n ; ++i ){
       dp[i][i] = arr[i] ; 
    }
    for( int i=2 ; i<=n ; ++i ){
        for( int j=0 ; j+i-1<n ; ++j ){
            dp[j][j+i-1] = max( dp[j][i+j-1] ,  arr[j] + ( prefix[j+i-1] - prefix[j] - dp[j+1][j+i-1] ) ) ; 
            dp[j][j+i-1] = max( dp[j][i+j-1] ,  arr[i+j-1] +( prefix[i+j-2] - ( j>0 ? prefix[j-1] : 0 ) - dp[j][j+i-2]   )  ) ;  
        }
    }
    ll rs = dp[0][n-1] ; 
    cout << rs << endl  ; 
    return 0 ; 
}