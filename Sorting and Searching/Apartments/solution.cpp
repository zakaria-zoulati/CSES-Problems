#include <iostream> 
#include <vector>
#include <algorithm>

typedef long long ll ; 

using namespace std ; 

int main() {
    int n , m ; 
    cin >> n >> m ; 
    ll k ; cin >> k ; 
    vector<ll> ai(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> ai[i] ; 
    }
    vector<ll> bi(m) ; 
    for( int i=0 ; i<m ; ++i ){
        cin >> bi[i] ; 
    } 
    sort( ai.begin() , ai.end() ) ; 
    sort( bi.begin() , bi.end() ) ; 

    int rs = 0 ; 
    int in = 0 ; 
    for( int i=0 ; i<n && in < m  ; ){
        if( ai[i] < bi[in] - k ){
            i++ ; 
        }else if( ai[i] > bi[in] + k ){
            in++  ;
        }else {
            in++ ; 
            i++ ; 
            rs++ ; 
        }   
    }

    cout << rs << endl ; 

    return 0 ; 
}