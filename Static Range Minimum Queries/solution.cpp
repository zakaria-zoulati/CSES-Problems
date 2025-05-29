#include <iostream>
#include <vector>

using namespace std ; 


int highest( int n ){
    int res = 0 ;
    while( n > 1 ){
        res++ ; 
        n >>= 1 ; 
    }
    return res ; 
}

int main(){
    int n ; cin >> n ; 
    int q ; cin >> q ; 
    vector<int> arr(n) ; 
    for(int i=0; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    // Build the sparse table 
    int k = highest( n  ); 
    vector< vector<int> > sparse( n , vector<int>(k+1) ) ; 
    for( int i=0 ; i<n ; ++i ){
        sparse[i][0] = arr[i] ; 
    }
    for( int j=1 ; j<=k ; ++j ){
        for( int i=0; i<n ; ++i ){
            if( i + ( 1L << j ) <= n ){
                sparse[i][j] = min( sparse[i][j-1] , sparse[i + (1<<(j-1) ) ][j-1] ) ; 
            }
        }
    }
    while( q-- ){
        int a , b ;
        cin >> a >> b ; 
        int len = ( b - a ) + 1; 
        int in = highest( len ) ; 
        int rs = min( sparse[a-1][in] , sparse[ b - ( 1 << in ) ][in] ) ; 
        cout << rs << endl ; 
    }
    return 0 ; 
}