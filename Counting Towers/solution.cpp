#include <iostream> 
#include <vector>
#include <utility>

using namespace std ; 

using ll = long long ; 

const int mod = 1e9 + 7 ; 

int main(){
    int t ; cin >> t ;
    vector< pair<ll ,ll>> dp( 1000001 ) ; 
    dp[1].first = 1 ; 
    dp[1].second = 1 ; 
    for( int i=2 ; i<=1000000 ; ++i ){
        dp[i].second = ( dp[i-1].first + 2*dp[i-1].second ) % mod ; 
        dp[i].first =  ( 4*dp[i-1].first + dp[i-1].second ) % mod ; 
    }
    while( t-- ){
        int n ; cin >> n ; 
        int rs = ( dp[n].first + dp[n].second ) % mod ; 
        cout << rs << endl ; 
    }
    return 0 ; 
}
