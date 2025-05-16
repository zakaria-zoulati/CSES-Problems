#include <iostream>
#include <vector>


using namespace std ; 
using ll = long long ; 


ll modE( ll n , ll k , ll mod ){
    if( k == 1 ){
        return n ; 
    }
    ll half = modE( n , k >> 1 , mod ) ; 
    half = ( half * half ) % mod ; 
    if( k % 2 == 1 ){
        half = ( half * n ) % mod ; 
    }
    return half ; 
}

const ll mod = 1e9 + 7 ; 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n ; cin >> n ; 
    if( n == 1 ){
        cout << 0 << endl ; 
        return 0 ; 
    }else if( n == 2 ){
        cout << 1 << endl ; 
        return  0 ; 
    }
    vector<ll> fact( n+1 ) ; 
    vector<ll> inv( n+1 ) ; 
    ll mod = 1e9 + 7 ; 
    fact[1] = 1 ; 
    inv[1] = 1 ; 
    inv[0] = 1 ; 
    for( int i=2 ; i<=n ; ++i ){
        fact[i] = ( fact[i-1] * i ) % mod ; 
    }
    inv[n] = modE( fact[n] , mod - 2 , mod ) ; 
    for( int i=n-1 ; i>=1 ; --i ){
        inv[i] = ( inv[i+1] * (i+1) ) % mod ; 
    } 
    ll rs = 0 ; 
    for( int i=0 ; i<=n ; ++i ){
        if( i % 2 == 0 ){
            rs = ( rs + inv[i] ) % mod ;  
        }else {
            rs = ( rs - inv[i] + mod ) % mod ; 
        }
    }
    rs = ( rs * fact[n] ) % mod ; 
    cout << rs << endl ; 
    return 0 ; 
}