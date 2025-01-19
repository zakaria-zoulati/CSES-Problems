#include <iostream>

using namespace std ; 

int main(){
    int n ; cin >> n ; 
    long long rs ; 
    long long curr ; 
    cin >> curr ; 
    rs = curr  ; 
    for( int i=1 ; i<n ; ++i ){
        long long e ; cin >> e ; 
        curr = max( curr + e , e ) ; 
        rs = max( rs , curr ) ; 
    }
    cout << rs  << endl ; 
    return 0;
}