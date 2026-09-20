#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<ll>; 
using vvi = vector<vi>;


unordered_map<ll,int> mapper1;
unordered_map<int,ll> mapper2;

struct SegTree {
    int n ; 
    vector<ll> tag , sum ; 

    SegTree( int n ) : n(n) , tag( 4*n ) , sum( 4*n ) {}

    void pull( int node , int l , int r ){
        if( tag[node] ){
            sum[node] = mapper2[r] - mapper2[l] ; 
        }else if( r - l == 1 ){
            sum[node] = 0 ; 
        }else {
            sum[node] = sum[2*node] + sum[2*node+1] ; 
        }
    }

    void update( int node , int l , int r , int ql , int qr , int v ){
        if( ql <= l && r <= qr ){
            tag[node] += v ; 
        }else {
            int mid = l + ( r - l )/2 ; 
            int lson = 2*node ; 
            int rson = 2*node + 1 ; 
            if( qr <= mid ){
                update( lson , l , mid , ql , qr , v ) ; 
            }else if( ql >= mid ){
                update( rson , mid , r , ql , qr , v ) ; 
            }else {
                update( lson , l , mid , ql , mid , v ) ; 
                update( rson , mid , r , mid , qr  , v ) ; 
            }
        }
        pull( node , l , r ) ; 
    }

    ll query(){
        return sum[1] ; 
    }
};

struct Seg {
    int x1 , x2 , y , v ;
    
    bool operator <( const Seg &seg ) const {
        return y < seg.y ; 
    }
};

void solve(){
    int n ; cin >> n ; 
    vvi coordinates(n , vi(4,1e6)); 
    vector<ll> vals ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<4 ; ++j ){
            ll val ; cin >> val ; 
            coordinates[i][j] += val ; 
            vals.push_back( coordinates[i][j] ) ; 
        }
    }
    
    sort( all(vals) ); 
    int len = 0 ; 
    for( int i=0 ; i<vals.size() ; ++i ){
        mapper1[vals[i]] = len ; 
        mapper2[len] = vals[i] ; 
        while( i+1<vals.size() && vals[i+1] == vals[i] ){
            i++ ; 
        }
        len++ ; 
    }

    SegTree seg(len); 

    vector<Seg> segments ; 
    for( int i=0 ; i<n ; ++i ){
       vi coord = coordinates[i] ; 
       segments.push_back( { mapper1[coord[0]] , mapper1[coord[2]] , mapper1[coord[1]] , 1 } ) ; 
       segments.push_back( { mapper1[coord[0]] , mapper1[coord[2]] , mapper1[coord[3]] , -1 } ) ; 
    }
    sort( all(segments) ) ; 

    ll ans = 0 ; 
    ll prevY = 0 ; 
    for( auto [x1,x2,y,v] : segments ){
        ans += ( seg.query() )*( mapper2[y] - prevY ) ; 
        seg.update( 1 , 0 , len-1, x1 , x2 , v ) ; 
        prevY=mapper2[y];
    }
    cout << ans << '\n' ; 
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