#include <iostream> 
#include <algorithm> 
#include <vector>

using namespace std ; 

typedef long long ll ; 


int main() {
    int n ; cin >> n ; 
    int x ; cin >> x ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort(  arr.begin() , arr.end())  ; 
    int l = 0 ; 
    int r = n-1 ; 
    int rs = 0 ; 
    while( l < r ){
        if( arr[l] + arr[r] <= x ){
            l++ ; 
            r-- ; 
            rs++ ; 
        }else {
            r-- ; 
            rs++ ; 
        }
    }
    if( l == r ) rs++ ; 

    cout << rs << endl ; 

    return 0 ; 
}