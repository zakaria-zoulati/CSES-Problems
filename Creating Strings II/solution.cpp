#include <iostream> 
#include <vector>
#include <unordered_set>
#include <string>

using namespace std ; 
using ll = long long ; 

ll modE( ll n , ll k , ll mod ){
    if( k == 1 ){
        return n ; 
    }
    ll half = modE( n , k/2 , mod ) ; 
    half = ( half * half ) % mod ; 
    if( k % 2 == 1 ){
        half = ( half * n ) % mod ; 
    }
    return half ; 
}


int main( ){
    string s ; cin >> s ; 
    int n = s.size() ; 
    vector<int> f( 26 , 0 ) ; 
    ll mod = 1e9 + 7 ; 
    for( auto c : s ){
        f[ c - 'a' ]++  ;
    }
    vector<ll> fact( n+1 , 0 ) ; 
    fact[0] = 1 ; 
    for( int i=1 ; i<=n ; ++i ){
        fact[i] = ( fact[i-1]*i ) % mod ; 
    }
    ll p = 1 ;
    for( int i=0 ; i<26 ; ++i ){
        p = ( p * fact[ f[i] ] ) % mod ; 
    }
    ll rs = fact[n] ; 
    rs = ( rs * modE( p , mod - 2 , mod ) ) % mod ; 
    cout << rs << '\n' ; 

}