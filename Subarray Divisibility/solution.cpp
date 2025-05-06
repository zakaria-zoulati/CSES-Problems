#include <iostream> 
#include <vector>

using namespace std ; 
using ll = long long ; 


int main(){
    int n ; cin >> n ; 
    ll rs = 0 ;     
    ll curr = 0 ; 
    vector<int> arr( n , 0 ) ; 
    arr[0] = 1; 
    for( int i=0 ; i<n ; ++i ){
        int ai ; cin >> ai ; 
        curr = ( n + curr + ( ai % n ) ) % n ; 
        rs += arr[curr]; 
        arr[curr]++ ; 
    }


    cout << rs << endl ; 
    return 0 ; 
}