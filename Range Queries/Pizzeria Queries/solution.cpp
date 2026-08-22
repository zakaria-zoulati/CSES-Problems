#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

struct SegmentTree{
    vector<int> seg ; 
    int n ; 
    
    SegmentTree(int n) : seg(4 * n, INT_MAX), n(n) {}

    int query( int node , int lo , int hi , int l , int r ){
        if( l > hi || r < lo ) return INT_MAX ; 
        int mid = lo + ( hi - lo )/2 ; 
        if( l <= lo && hi <= r ) return seg[node] ; 
        return min( 
            query( 2*node , lo , mid , l , r ) , 
            query( 2*node+1, mid+1 , hi , l , r ) 
        );
    }

    void update( int node , int lo , int hi , int k , int x ){
        if( lo == hi ){
            seg[node] = x ; 
            return ; 
        }
        int mid = lo + ( hi - lo )/2 ; 
        if( k <= mid ) update( 2 * node , lo, mid , k , x ) ;
        else update( 2 * node + 1,mid + 1 , hi , k , x  )  ;   
        seg[node] = min( seg[2*node] , seg[2*node+1] ) ; 
    }

    int query( int l , int r ){
        return query( 1 , 0 , n-1 , l , r ) ; 
    }

    void update( int k , int x ){
        return update( 1 , 0 , n-1 , k , x ) ; 
    }
};

void solve(){
    int n , q ; 
    cin >> n >> q ; 

    vector<int> p(n);
    for( int i=0 ; i<n ; ++i ){
        cin >> p[i];
    }

    SegmentTree seg1(n) ; 
    SegmentTree seg2(n) ; 
    for( int i=0 ; i<n ; ++i ){
        seg1.update( i , p[i] - i ); 
        seg2.update( i , p[i] + i ); 
    }

    while( q-- ){
        int t; cin>>t;
        if( t == 1 ){
            int k , x ; 
            cin >> k >> x ; 
            k-- ; 
            p[k] = x ; 

            seg1.update( k , p[k] - k ) ;
            seg2.update( k , p[k] + k ) ;
        }else { 
            int k ; cin >> k ; 

            k--;

            if( n == 1 ){
                cout << p[0] << '\n' ; 
            }else if( k == 0 ){
                cout << min( seg2.query( 0 , n-2 ) , p[0] )  << '\n' ;  
            }else if( k == n-1 ){
                cout << min( seg1.query( 0 , n-2 ) + n-1 , p[n-1] )  << '\n' ;  
            }else {
                int ans  = min( 
                    seg1.query( 0 , k-1 ) + k , 
                    seg2.query( k+1 , n-1 ) - k
                );

                cout << min( ans , p[k] ) << '\n' ; 
            }
        }
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