#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll helper( ll n ){
    if( n <= 10 ){
        return n + 1 ;
    }
    vector<ll> d ; 
    while( n > 0 ){
        d.push_back( n%10 ) ; 
        n /= 10 ; 
    } 
    int len = d.size() ; 

    vector<vector<vector<ll>>> dp( len , vector<vector<ll>>( 2 , vector<ll>( 10 , 0 ) ) ) ;  
    for( int i=0 ; i<=d[0] ; ++i ){
        dp[0][0][i] = 1 ; 
    }
    for( int i=0 ; i<10 ; ++i ){
        dp[0][1][i] = 1 ; 
    }
   
    for( int i=1 ; i<len ; ++i ){
        for( int j=0 ; j<10 ; ++j ){
            ll curr = 0 ; 
            for( int k=0 ; k<10 ; ++k ){
                if( k != j ){
                    curr += dp[i-1][1][k] ; 
                }
            }
            dp[i][1][j] = curr ; 
        }
       
        for( int j=0 ; j<d[i] ; ++j ){
            ll curr = 0 ; 
            for( int k=0 ; k<10 ; ++k ){
                if( k != j ){
                    curr += dp[i-1][1][k] ;
                }
            }
            dp[i][0][j] = curr ; 
        }
        
        ll curr = 0 ; 
        for( int j=0 ; j<10 ; ++j ){
            if( j != d[i] ){
                curr += dp[i-1][0][j] ; 
            }
        }
        dp[i][0][d[i]] = curr ; 
    }

    ll ans = 0 ; 
    for( int i=0 ; i<len-1 ; ++i ){
        for( int j=1 ; j<10 ; ++j ){
            ans += dp[i][1][j] ; 
        }
    }
    for( int i=1 ; i<=d[len-1] ; ++i ){
        ans += dp[len-1][0][i] ; 
    }
    return ans ; 
}

void solve(){
    ll a , b ; 
    cin >> a >> b ; 
    ll ans = helper(b) - helper(a-1) ; 
    cout << ans << '\n' ; 
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}