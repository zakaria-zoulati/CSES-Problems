#include <iostream> 
#include <vector> 
#include <algorithm> 

typedef long long ll ; 

using namespace std ; 

int main() {
    int n ; cin >> n ; 
    vector<int> arr( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    ll rs = 0 ; 
    int mid = arr[ n/2 ] ; 
    for( int i=0 ; i<n ; ++i ){
        rs += abs( arr[i] - mid ) ; 
    }

    cout << rs << endl ; 

    return  0 ; 
}