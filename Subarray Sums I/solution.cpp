#include <iostream> 
#include <vector> 

using namespace std  ; 
using ll = long long ; 


int main() {
    int n ; cin >> n ; 
    ll x ; cin >> x ;
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    int rs = 0 ; 
    int start = 0 ; 
    ll curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        curr += arr[i] ; 
        while( curr > x ){
            curr -= arr[start++] ; 
        }
        if( curr == x ){
            rs++ ; 
        }
    }
    cout << rs << endl ; 
    return 0 ; 
}
