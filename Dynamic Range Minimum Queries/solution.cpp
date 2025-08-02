#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>


using namespace std ; 
using ll = long long ; 


ll modE( ll n , ll k , ll mod ){
    if( k == 0 ){
        return 1 ; 
    }else if( k == 1 ){
        return n ; 
    }
    ll half = modE( n , k/2 , mod ) ; 
    ll  rs = ( half * half ) % mod ; 
    if( k & 1 ){
        rs = ( rs * n ) % mod ; 
    }
    return rs ; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n ; 
    int len = (int) sqrt( n + .0 ) + 1 ; 

    int q ; cin >> q ; 
    vector<int> arr(n) ; 

    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    vector<int> mo(len+1 , INT_MAX ) ; 
    for( int i=0 ; i<n ; i++ ){
        mo[ i/len ] = min( mo[i/len] , arr[i] ) ; 
    } 

    // for( int i=0 ; i<len ; ++i ){
    //     cout << mo[i] << '\n' ; 
    // }

    while( q-- ){
        int t ; cin >> t ; 
        int a  ; cin >> a ; 
        int b ; cin >> b ; 
        
        if( t == 1 ){
            a-- ; 
            if( arr[a] != mo[a/len] ){
                arr[a] = b ; 
                if( b < mo[a/len] ){
                    mo[a/len] = b ; 
                }
            }else {
                arr[a] = b ; 
                int s = (a/len)*len ; 
                int e = min( n-1 , s + len-1 ) ; 
                int rs = INT_MAX ; 
                for( int i=s ; i<=e ; ++i ){
                    rs = min( rs , arr[i] ) ; 
                }
                mo[a/len] = rs ; 
            } 
        }else{
            a-- ; b-- ; 
            int l = a/len ; 
            int r = b/len ; 
            int rs = INT_MAX ; 
            if( l == r ){
                for( int i=a ; i<=b ; ++i ){
                    rs = min( rs ,arr[i] ); 
                }
            }else {
                for( int i=a ; i<(l+1)*len ; ++i ){
                    rs = min( rs , arr[i] ) ; 
                }
                for( int i=l+1 ; i<=r-1 ; ++i ){
                    rs = min( rs , mo[i] ) ; 
                }
                for( int i=r*len ; i<=b ; ++i ){
                    rs = min( rs , arr[i] ) ; 
                }
            }
            cout << rs << '\n' ; 
        }
    }
    return 0 ; 
}


