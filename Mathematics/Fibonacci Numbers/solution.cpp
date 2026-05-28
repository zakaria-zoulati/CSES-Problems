#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 

const ll mod = 1e9 + 7 ; 

vector<vector<ll>> matMul( vector<vector<ll>> &a , vector<vector<ll>> &b ){
    vector< vector<ll> > rs( 2 , vector<ll>(2,0) ) ;
    for( int i=0 ; i<2 ; ++i ){
        for( int j=0 ; j<2 ; ++j ){
            for( int k=0 ; k<2 ; ++k ){
                rs[i][j] = ( rs[i][j] + a[i][k]*b[k][j] ) % mod ; 
            }
        }
    }
    return rs ; 
}

vector<vector<ll>> matExp( vector<vector<ll>> &a , ll n ){
   if( n == 1 ){
        return a ; 
   }
   vector<vector<ll>> half = matExp( a , n/2 ) ; 
   half = matMul( half , half ) ; 
   if( n % 2 == 1 ){
        half = matMul( half , a ) ; 
   } 
   return half ; 
}


int main() {
    ll n ; cin >> n ; 
    if( n <= 1 ){
        cout << n << endl ; 
    }else {
        vector< vector<ll> > base( 2 , vector<ll>(2 , 1) ) ; 
        base[1][1] = 0 ; 
        base = matExp( base , n-1 ) ; 
        cout << base[0][0] << endl ; 

    }
    return 0 ; 
}