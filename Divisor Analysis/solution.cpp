#include <iostream>
#include <vector>
#include <algorithm>


using namespace std ; 
using ll = long long ; 


ll modE( ll n , ll k , ll mod ){
    if( k == 0 ){
        return 1 ; 
    }else if( k == 1 ){
        return n ; 
    }
    ll half = modE( n , k/2 , mod ) ; 
    ll  rs = ( half * half ) % mod ; 
    if( k & 1 ){
        rs = ( rs * n ) % mod ; 
    }
    return rs ; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll mod = 1e9 + 7 ; 

    int n ; cin >> n ; 
    vector<ll> primes(n) ; 
    vector<ll> f(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> primes[i] >> f[i] ; 
    } 
    // The number of diviors 
    ll count = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        count = ( count * ( f[i] + 1 ) ) % mod ; 
    }


    // The sum of divisors 
    ll sum = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        ll a = modE( primes[i] , f[i] + 1 , mod ) ; 
        a = ( a - 1 + mod ) % mod ; 
        ll b = modE( primes[i] - 1 , mod - 2 , mod ) ; 
        a = ( a * b ) % mod ; 
        sum = ( sum * a ) % mod ; 
    }



    // THe product of divisors 
    ll p = 1 ;  
    vector<ll> helper( n , 1 ) ; 
    ll curr = 1 ;
    for( int i=0 ; i<n ; ++i ){
        helper[i] = curr ; 
        curr = ( curr * ( f[i] + 1 ) ) % ( mod - 1 ) ;   
    }
    curr = 1 ; 
    for( int i=n-1 ; i>=0 ; --i ){
        helper[i] = ( helper[i] * curr ) % ( mod - 1 ) ; 
        curr = ( curr * ( f[i] + 1 ) ) % ( mod - 1 ) ; 
    }
    for( int i=0 ; i<n ; ++i ){
        ll a = ( (ll) f[i] * ( f[i] + 1 )/2 ) % ( mod - 1 ) ;  
        a = ( a * helper[i] ) % ( mod - 1 ) ; 
        p = ( p * modE( primes[i] , a , mod ) ) % mod ; 
    }


    
    cout << count << " " << sum << " " << p << endl ;

    return 0 ; 
}