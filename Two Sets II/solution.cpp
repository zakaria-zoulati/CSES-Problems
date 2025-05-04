#include <iostream> 
#include <vector>

using namespace std ; 

using ll = long long ; 

int mod = 1e9 + 7 ; 

ll modE( ll x , int n  ){
    if( n == 1 ){
        return  x ; 
    }
    ll half = modE( x , n/2 ) ; 
    half = ( half * half ) % mod ; 
    if( n % 2 == 1 ){
        half = ( half * x ) % mod ; 
    }
    return half ; 
}

int main(){
   int n  ; cin >> n ; 
   int tar = n*( n + 1 ) /2 ; 
   if( tar % 2 == 1 ){
      cout << 0 << endl ; 
      return 0 ; 
   }
   tar >>= 1 ;
   vector<int> dp( tar + 1 , 0 ) ; 
   dp[0] = 1 ; 
   for( int i=1 ; i<=n ; ++i ){
      for( int j=tar ; j>=i ; --j ){
        dp[j] = ( dp[j] + dp[j-i] ) % mod ; 
    }
   }
   ll rs =  ( ( ll ) modE( 2, mod -2 ) * dp[tar] ) % mod ;  
    cout << rs << endl ; 
    return 0 ; 
}