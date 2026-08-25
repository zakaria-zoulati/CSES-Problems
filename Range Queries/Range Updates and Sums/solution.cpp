#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

struct SegTree{
    int n ;
    vector<ll> sum , addv , setv ; 
    vector<bool> hasSet ; 

    SegTree(int n) : n(n) , sum(4*n,0) , addv(4*n,0) , setv(4*n,0) , hasSet(4*n,false) {}

    void build( int node , int lo , int hi , vector<ll> &a ){
        if( lo == hi ) {
            sum[node] = a[lo] ; 
            return ;  
        }
        int mid = lo + ( hi - lo )/2 ; 
        build( 2*node , lo , mid , a ) ;
        build( 2*node+1 , mid+1 , hi , a ) ;
        sum[node] = sum[2*node] + sum[2*node+1];
    }   

    void applyAdd( int node , int len , ll x ){
        sum[node] += x * len ; 
        addv[node] += x ; 
    }

    void applySet( int node , int len  , ll x ){
        sum[node] = x * len ; 
        setv[node] = x ; 
        hasSet[node] = true ; 
        addv[node] =  0 ; 
    }

    void push( int node , int lo , int hi ){
        int mid = lo + ( hi - lo )/2 ; 
        int lenL = mid - lo + 1 , lenR = hi - mid ; 
        if( hasSet[node] ){
            applySet( 2*node , lenL , setv[node] ) ; 
            applySet( 2*node + 1 , lenR , setv[node] ) ; 
            hasSet[node] = 0; 
        }
        if( addv[node] ){
            applyAdd( 2*node , lenL , addv[node] ) ; 
            applyAdd( 2*node+1 , lenR , addv[node] );
            addv[node] = 0 ; 
        }
    }

    void rangeAdd( int node , int lo , int hi , int a , int b , ll x ){
        if( b < lo || a > hi ) return ; 
        if( a <= lo && hi <= b ) {
            applyAdd( node , hi - lo + 1 , x ) ; 
            return ; 
        }
        push( node , lo , hi ) ; 
        int mid = lo + ( hi - lo )/2 ; 
        rangeAdd( 2*node , lo , mid , a , b , x ) ;
        rangeAdd( 2*node+1,mid+1,hi, a , b , x ) ;
        sum[node] = sum[2*node] + sum[2*node+1] ; 
    }

    void rangeSet( int node , int lo , int hi , int a , int b , ll x ){
        if( b < lo || hi < a ) return ; 
        if( a <= lo && hi <= b ) {
            applySet( node , hi - lo + 1 , x ) ; 
            return ;
        }
        push( node , lo , hi ) ; 

        int mid = lo + ( hi - lo )/2 ; 
        rangeSet( 2*node , lo , mid , a , b , x ) ;
        rangeSet( 2*node+1 , mid + 1 , hi, a , b , x ) ;
        sum[node] = sum[ 2*node ] + sum[2*node+1] ; 
    }

    ll query( int node , int lo , int hi , int a , int b ){
        if( b < lo || a > hi ){
            return 0LL ; 
        }
        if( a <= lo && hi <= b ){
            return sum[node] ; 
        }
        push( node , lo , hi ) ; 
        int mid = lo + ( hi - lo )/2 ; 
        return (
            query( 2*node , lo , mid , a , b ) + 
            query( 2*node+1 , mid+1 , hi, a , b )
        )  ; 
    }
};

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , q ; 
    cin >> n >> q ; 

    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    SegTree seg(n) ;
    seg.build( 1 , 0 , n-1 , arr ); 

    while( q-- ){
        int t ; cin >> t ; 
        int a , b ; 
        cin >> a >> b ; 
        a-- ; b-- ;

        if( t == 1 ){
            ll x ; cin >> x ;
            seg.rangeAdd( 1 , 0 , n-1 , a , b , x ) ; 
        }else if( t == 2 ){
            ll x ; cin >> x ;  
            seg.rangeSet( 1 , 0 , n-1 , a , b , x ) ; 
        }else { 
            cout << seg.query( 1 , 0 , n-1 , a , b ) << '\n' ; 
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