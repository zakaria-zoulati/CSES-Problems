#include <iostream>
#include <vector>
#include <algorithm>


using namespace std ; 
using ll = long long ; 

int main(){
    ll n ; cin >> n ;
    int k ; cin >> k ; 
    vector<ll> primes(k) ; 
    for( int i=0 ; i<k ; ++i ){
        cin >> primes[i] ; 
    }
    int len = ( 1 << k ) ; 
    ll rs = 0 ; 
    for( int i=1 ; i<len ; ++i ){
        ll curr = i ;  
        int s = __builtin_popcount( i ) % 2 == 1 ? 1 : -1 ; 
        ll product = 1 ; 
        bool fl = false ; 
        int in = 0 ; 
        while( curr > 0 ){
            if( curr & 1 ){
                if( n / product >= primes[in] ){
                    product *= primes[in] ; 
                }else {
                    fl = true ;
                    break ; 
                }
            }
            curr >>= 1 ; 
            in++ ; 
        }
        if( fl ) continue ; 
        rs = rs + s*( n / product ) ; 
    }

    cout << rs << endl ; 

    return 0 ; 
}