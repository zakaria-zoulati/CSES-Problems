#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll tree[2'000'001] ; 
int n , q ; 

void update( int i , ll delta ){
    while( i <= n ){
        tree[i] += delta ; 
        i += i & (-i); 
    }
}

ll query( int i ){
    ll s = 0 ; 
    while( i > 0 ){
        s += tree[i];
        i -= i & (-i); 
    }
    return s ; 
}

void solve(){
    cin >> n >> q ; 
    
    ll prev = 0 ;
    for( int i=1 ; i<=n ; ++i ){
        ll x ; cin >> x ; 
        update( i , x-prev ); 
        prev = x ;
    }

    while( q-- ){
        int t ; cin >> t ; 
        if( t == 1 ){
            int a , b ; 
            cin >> a >> b ; 
            int k; cin >> k; 
            update( a , k ); 
            if( b + 1 <= n ){
                update( b+1, -k );
            }
        }else {
            int k ; cin >> k ; 
            cout << query(k) << '\n';
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