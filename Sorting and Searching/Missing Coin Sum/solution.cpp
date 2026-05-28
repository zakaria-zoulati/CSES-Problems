#include <iostream>  
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std ; 

typedef long long ll ; 

int main(){
    int n ; cin >> n ; 
    vector<ll> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    ll target = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        if( arr[i] <= target ){
            target += arr[i] ; 
        }else {
            break ; 
        }
    }

    cout << target << endl ;

    return 0 ; 
}
