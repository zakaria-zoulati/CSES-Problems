#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 


bool check( ll target , vector<int> &arr , int t ){
    ll curr = 0 ; 
    for( int i : arr ){
        curr +=  target / i  ; 
    }
    return curr >= t ; 
}

int main(){
    int n ; cin >> n ; 
    int t ; cin >> t ; 
    vector<int> arr(n) ; 
    int m = 1e9 ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
        m = min( arr[i] , m ) ; 
    }
    ll l = m ; 
    ll r = (ll) m*t ; 
    while( l < r ){
        ll mid = l + ( r - l )/2 ; 
        if( check( mid , arr , t ) ){
            r = mid ; 
        }else {
            l = mid + 1 ; 
        }
    }   

    cout << l << endl ; 

    return 0 ; 
}