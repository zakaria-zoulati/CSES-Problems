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
    int k = highest( n ); 
    vector< vector<int> > sparse( n , vector<int>(k+1) ) ; 
    for( int i=0 ; i<n ; ++i ){
        sparse[i][0] = arr[i] ; 
    }
    for( int j=1 ; j<=k ; ++j ){
        for( int i=0; i<n ; ++i ){
            if( i + ( 1L << j ) <= n ){
                sparse[i][j] =  sparse[i][j-1] ^ sparse[i + (1<<(j-1) ) ][j-1]  ; 
            }
        }
    }
    while( q-- ){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;  
        int diff = b - a + 1 ; 
        int rs = 0 ; 
        if( diff == 1 ){
            rs = arr[a] ; 
        }else {
            while( diff > 0 ){
                int curr = diff & -diff ; 
                int k = highest(curr) ; 
                rs ^= sparse[a][k] ; 
                diff -= curr ; 
                a += curr ; 
            }
        }
        cout << rs << "\n" ; 
    }
    return 0 ; 
}