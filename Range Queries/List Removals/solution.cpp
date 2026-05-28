#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

struct BIT {
    vector<int> bit ; 
    int n ; 
    BIT( int len ){
        n = len+1 ; 
        bit.assign( n , 0 ) ; 
        for( int i=1 ; i<=n ; ++i ){
            update( i , 1 ) ; 
        }
    }
    int get( int idx ){
        int ans = 0 ; 
        while( idx > 0 ){
            ans += bit[idx] ; 
            idx -= idx&-idx ; 
        }
        return ans ; 
    }
    void update(int idx , int diff ){
        while( idx < n ){
            bit[idx] += diff ; 
            idx += idx &-idx;  
        }
    }
};

int getPos( BIT &bit , int pos ){
    int l=1 ; 
    int r=bit.n; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        int count = bit.get( mid ) ; 
        if( count >= pos ){
            r = mid ; 
        }else {
            l = mid + 1 ; 
        }
    }
    return l ; 
}


void solve(){
    int n ; cin >> n ; 
    vector<int> eles(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> eles[i] ; 
    }
    vector<int> pos(n) ; 
    for( int i=0; i<n ; ++i ){
        cin >> pos[i] ; 
    }

    BIT bit( n ) ; 

    for( int i=0 ; i<n ; ++i ){
        int p = getPos( bit , pos[i] ) ; 
        cout << eles[p-1] << " "  ; 
        bit.update( p , -1 ) ; 
    }

}
int main() {
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}