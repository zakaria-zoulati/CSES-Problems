#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

struct SegmentTree{
    vector<ll> seg ; 
    vector<ll> maxPref;
    vector<ll> maxSuff;
    vector<ll> sum ; 
    int n ; 
    
    SegmentTree(int n) : seg(4 * n, 0), maxPref( 4*n , 0 ) , maxSuff( 4*n , 0 ), sum(4*n,0) , n(n) {}

    void update( int node , int lo , int hi , int k , int x ){
        if( lo == hi ){
            seg[node] = max( x , 0 ) ; 
            sum[node] = x ; 
            maxPref[node] = max( 0 , x ) ;   
            maxSuff[node] = max( 0 , x ) ;   
            return ; 
        }

        int mid = lo + ( hi - lo )/2 ; 
        if( k <= mid ) update( 2 * node , lo, mid , k , x ) ;
        else update( 2 * node + 1,mid + 1 , hi , k , x  )  ;   


        sum[node] = sum[2*node] + sum[2*node+1] ; 
        maxPref[node] = max( maxPref[2*node] , sum[2*node] + maxPref[2*node+1] ) ; 
        maxSuff[node] = max( maxSuff[2*node+1] , sum[2*node+1] + maxSuff[2*node] ) ; 
    
        seg[node] = max( seg[2*node] , seg[2*node+1] ) ; 
        seg[node] = max( seg[node] , maxSuff[2*node] + maxPref[2*node+1] ) ; 
    }

    ll query(){
        return seg[1] ;  
    }

    void update( int k , int x ){
        return update( 1 , 0 , n-1 , k , x ) ; 
    }
};

void solve(){
    int n , q ; 
    cin >> n >> q ; 

    SegmentTree seg(n) ; 

    for( int i=0 ; i<n ; ++i ){
        int x ; cin >> x ; 
        seg.update( i , x ) ; 
    }

    while( q-- ){
        int k , x ; 
        cin >> k >> x ; 
        seg.update( k-1 , x ) ; 
        cout << seg.query() << '\n' ;
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}