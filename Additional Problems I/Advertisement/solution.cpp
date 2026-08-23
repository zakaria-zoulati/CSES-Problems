#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

struct SegmentTree{
    int n ; 
    vector<ll> seg ; 

    SegmentTree( int n ) : n(n) , seg( 4 * n , LLONG_MAX ) {}

    void update( int k , ll x ){
        update( 1 , 0 , n-1 , k , x ) ; 
    }

    void update( int node, int lo, int hi , int k , ll x ){
        if( lo == hi ){
            seg[node] = x ; 
            return ; 
        }

        int mid = lo + ( hi - lo )/2 ; 

        if( k <= mid ){
            update( 2*node,lo ,mid,k,x ); 
        }else {
            update( 2*node+1,mid+1,hi,k,x ) ;
        }
        seg[node] = min( seg[2*node] , seg[2*node+1] ); 
    }

    int getLeft( int l , ll val ){
        return getLeft( 1 , 0 , n-1 , l , val ) ; 
    }
    int getLeft( int node , int lo , int hi , int l , ll val ){
        if( l < lo ){
            return n+1 ; 
        }
        if( seg[node] >= val ){
            return lo ; 
        }
        if( lo == hi ){
            return ( seg[node] >= val ? lo : n+1 ) ; 
        }
        int mid = lo + ( hi - lo )/2 ; 
        if( l >= mid + 1 ){
            int ans = getLeft( 2*node+1,mid+1,hi,l,val );
            if( ans == mid+1 ){
                ans = min( ans , getLeft( 2*node,lo,mid,l,val ) );
            }
            return ans;
        }else {
            return getLeft( 2*node , lo , mid , l , val ) ; 
        }
    }
    
    int getRight( int r , ll val ){
        return getRight( 1 , 0 , n-1 , r , val ) ; 
    }
    int getRight( int node , int lo , int hi , int r , ll val ){
        if( r > hi ){
            return -1 ;
        }
        if( seg[node] >= val ){
            return hi ; 
        }
        if( lo == hi ){
            return ( seg[node] >= val ? lo : -1 ) ;  
        }
        int mid = lo + ( hi - lo )/2 ; 
        if( r <= mid ){
            int ans = getRight( 2*node,lo,mid,r,val );
            if( ans == mid ){
                ans = max( ans , getRight( 2*node+1,mid+1,hi,r,val ) );
            }
            return ans;
        }else {
            return getRight( 2*node+1 , mid+1 ,hi, r ,val ) ; 
        }
    }

};

void solve(){
    int n ; cin >> n ; 
    vector<ll> arr(n) ; 

    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i];
    }    

    SegmentTree seg( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        seg.update( i , arr[i] ) ; 
    }
   
    ll ans = 0; 

    for( int i=0 ; i<n ; ++i ){
        int l = seg.getLeft(i,arr[i]); 
        int r = seg.getRight(i,arr[i]);
        
        ans = max( ans , arr[i]*( r - l + 1 ) ); 
        while( i+1<n && arr[i+1] == arr[i] ) i++ ; 
    }
    cout << ans << '\n'; 
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