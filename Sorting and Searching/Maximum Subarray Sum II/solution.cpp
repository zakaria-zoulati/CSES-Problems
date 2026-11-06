#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


ll query( vector<vector<ll>> &sparse , int l , int r ){
    int k = log2( r - l + 1 ) ;
    return min( sparse[l][k] , sparse[r-(1<<k)+1][k] ) ; 
}

void solve(){
    int n ; cin >> n ; 
    int a , b ; 
    cin >> a >> b ; 

    vector<ll> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    int k = log2(n);
    vector<vector<ll>> sparse( n , vector<ll>(k+1) );
    sparse[0][0] = arr[0];
    for( int i=1 ; i<n ; ++i ){
        sparse[i][0] = sparse[i-1][0] + arr[i];
    }

    for( int j=1 ; j<=k ; ++j ){
        for( int i=0 ; i<n ; ++i ){
            if( i + ( 1 << j  ) <= n ){
                sparse[i][j] = min( sparse[i][j-1] , sparse[i+( 1 << (j-1) ) ][j-1] ) ; 
            }else {
                break ; 
            }
        }
    }

    vector<ll> pref(n);
    pref[0] = arr[0];
    for( int i=1 ; i<n ; ++i ){
        pref[i] = pref[i-1] + arr[i] ; 
    } 

    ll ans = pref[a-1] ; 
    for( int i=0 ; i<n ; ++i ){
        if( i<=a-1 ) continue ;
        if( i < b ){
            ans = max( ans , pref[i] ) ; 
        }
        ans = max( ans , pref[i] - query( sparse , max( i - b , 0 ) , i - a ) ) ; 
    }


    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}