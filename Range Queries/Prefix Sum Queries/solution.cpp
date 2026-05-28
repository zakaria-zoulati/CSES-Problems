#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;

struct Seg {
    int n ; 
    vector<ll> sum ; 
    vector<ll> pref ; 
    Seg( vector<ll> &arr ){
        n = arr.size() ; 
        sum.resize( 4*n ) ; 
        pref.resize( 4*n ) ; 
        build( arr , 1 , 0 , n-1 ) ; 
    }
    void build( vector<ll> &arr , int node , int l , int r ){
        if( l == r ){
            sum[node] = arr[l] ; 
            pref[node] = max( 0LL , arr[l] ) ; 
            return ; 
        }
        int mid = ( l + r )/2 ; 
        build( arr , 2*node , l , mid ) ; 
        build( arr , 2*node +1 , mid +1 ,  r ) ; 
        sum[node] = sum[2*node] + sum[2*node+1] ; 
        pref[node] = max( pref[2*node] , sum[2*node] + pref[2*node+1] ) ; 
    }
    void update( int idx , int val ){
        update( 1 , 0 , n-1 , idx , val ) ; 
    }
    void update( int node , int l , int r , int idx , ll val ){
        if( l == r ){
            sum[node] = val ; 
            pref[node] = max( 0LL , val ) ; 
            return ;  
        }
        int mid = ( l + r )/2 ; 
        if( idx <= mid ) update( 2*node , l , mid , idx , val ) ; 
        else update( 2*node+1 , mid + 1 , r , idx , val ) ; 
        sum[node] = sum[2*node] + sum[2*node+1] ; 
        pref[node] = max( pref[2*node] , sum[2*node] + pref[2*node+1] ) ; 
    }
    ll query(int ql , int qr){
        return query( 1 , 0 , n-1 , ql , qr ) ; 
    }
    ll getSum( int node , int l , int r , int ql , int qr ){
        if( qr < l || ql > r ) return 0 ; 
        if( ql <= l && r <= qr ){
            return sum[node] ; 
        }
        int mid = ( l + r )/2 ; 
        ll left = getSum( 2*node , l , mid , ql , qr ) ; 
        ll right = getSum( 2*node + 1 , mid+1 , r , ql , qr ) ; 
        return left + right ; 
    }
    ll query( int node , int l , int r , int ql , int qr ){
        if( qr < l || ql > r ) return 0 ; 
        if( ql <= l && r <= qr ){
            return pref[node] ; 
        }
        int mid = ( l + r )/2 ; 
        ll left = query( 2*node , l , mid , ql , qr ) ; 
        ll right = query( 2*node + 1 , mid+1 , r , ql , qr ) ; 
        ll rs = max( left , getSum( 2*node , l , mid , ql , qr ) + right ) ;   
        return rs ; 
    }
};


void solve(){
    int n ; cin >> n ; 
    int q ; cin >> q; 
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    Seg seg( arr ) ; 
    while( q-- ){
        int t;cin>> t; 
        if( t == 1 ){
            int k ; cin >> k ;
            ll u ; cin >> u ;
            k-- ; 
            seg.update( k , u );  
        }else {
            int a, b ; 
            cin >> a >> b ; 
            a-- ; b-- ; 
            ll rs = seg.query( a , b ) ; 
            cout << rs << '\n'; 
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