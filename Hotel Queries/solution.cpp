#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;

struct Seg {
    int n ; 
    vector<ll> maxi ; 
    Seg( vector<ll> &rooms ){
        n = rooms.size() ; 
        maxi.resize( 4*n ) ; 
        build( rooms , 1 , 0 , n-1 ) ; 
    }
    void build( vector<ll> &arr , int node , int l , int r ){
        if( l == r ){
            maxi[node] = arr[l] ; 
            return ; 
        } 
        int mid = ( l + r )/2 ; 
        build( arr , 2*node , l , mid ) ; 
        build( arr , 2*node +1 , mid+1 , r ) ; 
        maxi[node] = max( maxi[2*node] , maxi[2*node+1] ) ; 
    }

    void update( int room , ll val ){
        update( 1 , 0 , n-1 , room , val ) ; 
    }

    void update( int node , int l , int r , int room , int val ){
        if( l == r ){
            maxi[node] -= val ; 
            return ; 
        }
        int mid = ( l + r )/2 ; 
        if( room <= mid ) update( 2*node , l , mid , room , val ) ;  
        else update( 2*node+1 , mid+1 , r , room , val ) ; 
        maxi[node] = max( maxi[2*node] , maxi[2*node+1] ) ;  
    }

    int query( ll g ){
        return query( 1 , 0 , n-1 , g ) ; 
    }

    int query( int node , int l , int r , ll g ){
        if( l == r ){
            if( maxi[node] >= g ){
                return l ; 
            }
            return -1 ; 
        } 
        if( maxi[node] < g ){
            return -1 ;
        }
        int mid = ( l + r )/2 ; 
        int a = query( 2*node , l, mid , g ) ; 
        if( a != -1 ){
            return a ; 
        }
        return query( 2*node+1 , mid+1 , r , g ) ; 
    }
};

void solve(){
    int n , m ;
    cin >> n >> m ; 
    vector<ll> h(n) ; 
    for( int i=0; i<n ; ++i ){
        cin >> h[i] ; 
    }   
    Seg seg( h ) ;
    for( int i=0 ; i<m ; ++i ){
        ll g ; cin >> g ; 
        int room = seg.query( g ) ; 
        if( room != -1 ){
            cout << room+1 << " " ; 
            seg.update( room , g ) ;  
        }else {
            cout << 0 << " " ; 
        }     
    }
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}