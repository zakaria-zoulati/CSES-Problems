#include <iostream> 


using namespace std ; 
using ll = long long ;

int mod = 1e9 + 7 ; 

const int inf = 1000001 ; 

ll fact[inf] ; 
ll invFact[inf] ; 

ll modE( ll k , int n ){
    if( n == 1 ){
        return k ; 
    }
    ll half = modE( k , n/2 ) ; 
    half = ( half * half ) % mod ; 
    if( n % 2 == 1 ){
        half = ( half * k ) % mod ; 
    }
    return half ; 
}

void precompute(){
    fact[0] = 1 ; 
    for( int i=1 ; i<inf ; ++i ){
        fact[i] = ( fact[i-1]*i ) % mod ; 
    }
    invFact[inf-1] = modE( fact[inf-1] , mod - 2  ) ; 
    invFact[0] = 1 ; 
    invFact[1] = 1 ; 
    for( int i=inf-2 ; i>=2 ; --i ){
        invFact[i] = ( invFact[i+1] *( i+1 ) ) % mod ; 
    }
}


int main(){
    
    precompute() ; 
    int n ; cin >> n ; 
    while( n-- ){
        int a , b ; 
        cin >> b >> a ; 
        ll rs = fact[b] ; 
        rs = ( rs * invFact[a]) % mod ; 
        rs = ( rs * invFact[b-a]) % mod ; 
        
        cout << rs << endl ; 
    }


    return 0 ; 
}