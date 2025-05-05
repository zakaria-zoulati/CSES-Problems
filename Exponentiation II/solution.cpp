#include <iostream>

using namespace std ; 
using  ll = long long  ; 

int mod =  1e9 + 7 ; 

ll modE( ll a, ll n , ll mod ){
    if( n == 1 ){
        return a ; 
    }else if( n == 0 ){
        return 1 ; 
    }
    ll half = modE( a , n/2 , mod ) ; 
    half = ( half * half ) % mod  ; 
    if( n % 2 == 1 ){
        half = ( half * a ) % mod ;
    }
    return half ; 
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n ; cin >> n ; 
    while( n-- ){
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        ll ex = modE( b , c , mod -1) ; 
        ll rs = modE( a , ex , mod ) ; 
        cout << rs << endl ; 
    }
    return 0 ; 
}