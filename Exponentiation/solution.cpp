#include <iostream>

using namespace std ; 

long long mod = (1e9) + 7 ; 

long long modE(long long a, long long b){
    if( b == 0 ){
        return 1 ; 
    }
    if( b == 1 ){
        return a ; 
    }
    long long curr = (a * a) % mod ; 
    if( b % 2 == 0 ){
        return modE( curr , b/2 ) ; 
    }else {
        return (a*modE(curr,b/2) ) % mod ; 
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n ; cin >> n ; 
    while( n-- ){
        long long a ; cin >> a  ; 
        long long b ; cin >> b ; 
        cout << modE(a,b) << "\n" ; 
    }
    return 0 ; 
}


