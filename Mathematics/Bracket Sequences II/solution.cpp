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
    string s ; cin >> s ; 
    if( n % 2 == 1 ){
        cout << 0 << endl ; 
        return 0 ; 
    }
    n >>= 1 ; 
    ll mod = 1e9 + 7 ; 
    int left = 0 ; 
    int right = 0 ; 
    int curr = 0 ; 
    for( char c : s ){
        if( c == '(' ){
            left++ ; 
            curr++ ; 
        }else {
            right++ ; 
            curr--; 
            if( curr < 0 ){
                cout << 0 << '\n' ; 
                return 0  ; 
            }
        }
    }
    if( left > n || right > n ){
        cout << 0 << '\n' ; 
        return 0 ;
    }
    int l = n - right ; 
    int r = n - left ; 
    if( l + r <= 1 ){
        cout << 1 << '\n' ; 
    }else {
        vector<ll> fact(l+r+1) ;
        fact[0] = 1 ; 
        for( int i=1; i<=l+r ; ++i ){
            fact[i] = ( fact[i-1] * i ) % mod ;  
        }
        ll a = ( fact[l+r] * modE( fact[l] , mod -2 , mod ) ) % mod ; 
        a = ( a * modE( fact[r] , mod - 2 , mod ) ) % mod ; 
        ll b = ( fact[l+r] * modE( fact[l+1] , mod -2 , mod ) ) % mod ; 
        b = ( b * modE( fact[r-1]  , mod - 2 , mod ) ) % mod ; 
        ll rs = ( a - b + mod ) % mod ; 
        cout << rs << '\n' ; 
    }

    return 0 ; 
}