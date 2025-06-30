#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 


int main(){
    int n , m ; 
    cin >> n >> m ; 
    vector<int> a(n) ;
    vector<int> b(m) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }
    for( int i=0 ; i<m ; ++i ){
        cin >> b[i] ; 
    } 
    vector<vector<int>> dp( n+1 , vector<int>( m+1 , 0 ) ) ; 
    for( int i=1 ; i<=n ; ++i){
        for( int j=1 ; j<=m ; ++j ){
            if( a[i-1] == b[j-1] ){
                dp[i][j] = 1 + dp[i-1][j-1] ; 
            }else {
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) ; 
            }
        } 
    }
    vector<int> rs ;
    int i=n , j=m ; 
    while( i>0 && j>0 ){
        if( a[i-1] == b[j-1] ){
            rs.push_back( a[i-1] ) ; 
            i-- ; 
            j-- ; 
        }else if( dp[i-1][j] > dp[i][j-1] ) {
            i-- ; 
        }else {
            j-- ; 
        }
    }
    cout << rs.size() << '\n' ; 
    for( int i=rs.size() - 1 ; i>=0 ; --i ){
        cout << rs[i] << " " ; 
    }
    cout << '\n' ; 

    return 0 ;  
}