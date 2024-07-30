#include <iostream> 
using namespace std ;
int main(){
    long long n ; cin >> n ;
    long long inter = 1e9 +7 ; 
    long long rs = 1; 
    while( n>0 ){
        rs = rs*2 % inter ; 
        n-- ; 
    }
    cout << rs << endl ; 
    return 0 ; 
}

