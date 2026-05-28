#include <iostream> 
#include <vector>   
#include <climits>

using namespace std ; 
using ll = long long ; 


bool check( ll tar , vector<int> &arr , int k ){
    int n = arr.size() ; 
    int seg = 1 ;
    ll curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] > tar ) return false ; 
        curr += arr[i] ; 
        if( curr > tar ){
            seg++ ; 
            curr = arr[i] ; 
        }
    }
    return seg <= k ; 
}

int main( ){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> arr( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    ll rs = 0 ; 
    ll l = 1 ; 
    ll r = LONG_MAX ; 
    while( l < r ) {
        ll mid = l + ( r - l )/2 ; 
        if( check( mid , arr , k )  ){
            r = mid ; 
        }else {
            l = mid + 1; 
        }
    }

    cout << l << endl ; 
    return 0 ; 
}