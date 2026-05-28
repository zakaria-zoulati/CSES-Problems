#include <iostream>
#include <vector>

using namespace std;
using ll = long long ; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ; cin >> n ; 
    ll rs = 0; 
    for( ll i = 0 ; i < 60 ; ++i ){
        if( (1LL << i) > n  ){
            break ; 
        }
        ll els = n - ( 1LL<<i ) + 1; 
        ll groups = ( els )/( 1LL << i ) ; 
        ll rest = els % ( 1LL << i ) ; 
        rs += (( groups + 1 )/2)*( 1LL << i ) ; 
        if( groups % 2 == 0 ){
            rs += rest ; 
        } 
    }
    cout << rs << '\n'; 
}
