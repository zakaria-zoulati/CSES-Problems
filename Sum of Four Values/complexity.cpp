#include <iostream>

using namespace std ; 
using ll = long long ; 

// This simple funtion is to calculate the max ops that can be done in worst case

int main() {
    int n = 1000 ;
    ll cost = 0 ; 
    for( int i = 4 ; i<=n ; ++i ){
        cost += ( n - (i-1) )*( i-2 ) ; 
    }
    cout << cost << endl ; 

    return 0 ; 
}