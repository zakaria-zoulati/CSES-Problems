#include <iostream>
#include <vector>

using namespace std ;
using ll = long long ; 


const ll mod = 1e9 + 7 ; 

ll modE( ll n , ll m ){
    if( m == 0 ){
        return 1 ; 
    }
    if( m == 1 ){
        return n ; 
    }
    ll half = modE( n , m >> 1 ) ; 
    half = ( half * half ) % mod ; 
    if( m & 1 ){
        half = ( half * n ) % mod ; 
    }
    return half ; 
}

int main(){
    int n , m ; 
    cin >> n >> m ; 
    
    if( n == 1 ){
        cout << 1 << endl ; 
    }else if( m == 1 ){
        cout << n << endl ; 
    }else {
        vector<ll> fact(n+m) ; 
        fact[1] = 1 ; 
        for( int i=2 ; i<n+m ; ++i ){
            fact[i] = ( fact[i-1]*i ) % mod ; 
        }
        int x = max( n + 1 , m + 1 ) ; 
        vector<ll> revFact( x ) ; 
        revFact[x-1] = modE( fact[x-1] , mod -2 ) ;
        for( int i = x-2 ; i>=1 ; --i ){
            revFact[i] = ( revFact[i+1] * (i+1) ) % mod ; 
        }
        ll rs = fact[m+n-1] ; 
        rs = ( rs * revFact[m] ) % mod ; 
        rs = ( rs * revFact[n-1] ) % mod ; 
        cout << rs << endl ; 
    }

    return 0 ; 
}