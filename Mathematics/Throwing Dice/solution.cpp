#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std ; 
using ll = long long ; 

ll mod = 1e9 + 7 ;

vector<vector<ll>> matM( vector<vector<ll>> &A , vector<vector<ll>> &B , ll mod ){
    vector<vector<ll>> RS( 6 , vector<ll>(6,0) ) ; 
    for( int i=0 ; i<6 ; ++i ){
        for( int j=0 ; j<6 ; ++j ){
            for( int k=0 ; k<6 ; ++k ){
                RS[i][j] = ( RS[i][j] + A[i][k]*B[k][j] ) % mod ; 
            }
        }
    }
    return RS ; 
}

vector<vector<ll>> matE( vector<vector<ll>> &A , ll p , ll mod ){
    if( p == 1 ){
        return A ; 
    }
    vector<vector<ll>> RS = matE( A , p/2 , mod ) ;
    RS = matM( RS , RS , mod ); 
    if( p % 2 == 1 ){
        return matM( RS , A , mod ) ; 
    }
    return RS ; 
}

int main(){
    ll n ; cin >> n ; 
    vector<int> dp( 7 ) ; 
    dp[0] = 1; 
    for( int i=1 ; i<=6 ; ++i ){
        for( int j=1 ; j<=6 ; ++j ){
            if( i - j < 0 ) break ; 
            dp[i] += dp[i-j] ; 
        }
    }
    if( n <= 6 ){
        cout << dp[n] << '\n' ; 
    }else {
        vector<vector<ll>> A( 6 , vector<ll>(6,0) ) ; 
        for( int i=0 ; i<6 ; ++i ){
            A[0][i] = 1 ; 
        }
        for( int j=1 ; j<6 ; ++j ){
            A[j][j-1] = 1 ; 
        }
        ll rest = n - 6 ; 
        vector<vector<ll>> B = matE( A , rest , mod ) ; 
        ll rs = 0 ; 
        for( int i=0 ; i<6 ; ++i ){
            rs = ( rs + B[0][i]*dp[6-i] ) % mod ; 
        }
        cout << rs << '\n' ; 
    }
    return 0 ; 
}