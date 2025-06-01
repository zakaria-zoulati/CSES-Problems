#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 


ll modE( ll b , ll k , ll mod ){
    if( k == 1 ){
        return b ; 
    }
    ll half = modE( b , k/2 , mod ) ; 
    half = ( half * half ) % mod ; 
    if( k % 2 == 1 ){
        half = ( half * b ) % mod ; 
    }
    return half ; 
}


int main(){
    int n ; cin >> n ; 
    if( n % 2 == 1 ){
        cout << 0 << endl ; 
        return 0 ; 
    }
    n >>= 1 ; 
    ll mod = 1e9+7 ;
    vector<ll> fact( 2*n+1 ) ; 
    fact[1] = 1 ; 
    for( int i=2 ; i<=2*n ; ++i ){
        fact[i] = ( fact[i-1] * i ) % mod ; 
    }
    vector<ll> inFact( n+1 ) ;
    inFact[n] = modE( fact[n] , mod-2 , mod ) ;
    for( int i=n-1 ; i>=1 ; --i ){
        inFact[i] = ( inFact[i+1]*(i+1) ) % mod ; 
    }
    ll rs = (fact[2*n]*inFact[n] ) % mod ; 
    rs = ( rs * inFact[n] ) % mod ; 
    rs = ( rs * modE( n+1 , mod - 2 , mod ) ) % mod ; 

    cout << rs << endl ; 

    return 0 ; 
}