#include <iostream>

using namespace std ; 
using ll = long long ; 

void solve( ll n ){
    ll prev = 0 ; 
    ll start = 1 ; 
    int digits = 1 ;
    while( prev + 9*digits*start < n ){
        prev += 9*digits*start ; 
        digits++ ; 
        start *= 10 ; 
    }

    n -= prev ; 
    start += (n-1)/digits ; 
    int pos = digits - (  (n-1) % digits )  ;
    int in = 1 ; 
    while( in != pos ){
        start /= 10 ; 
        in++  ; 
    }
    cout << start % 10 << endl ; 
}

int main(){
    int q ; cin >> q ; 
    while( q-- ){
        ll n ; cin >> n ;
        solve(n) ; 
    }
    return 0 ; 
}