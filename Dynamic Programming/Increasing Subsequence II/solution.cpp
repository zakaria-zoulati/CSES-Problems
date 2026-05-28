#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long ; 

ll mod = 1e9 + 7 ; 

struct BIT {
    vector<int> bit ; 
    int n ; 
    BIT( int len ){
        n = len ; 
        bit.assign(  n+1 , 0 ); 
    }
    int get( int idx ){
        int rs = 0 ; 
        while( idx > 0 ){
            rs = ( rs + bit[idx] ) % mod ; 
            idx -= idx&-idx  ; 
        }
        return rs ; 
    }
    void update( int pos , int val ){
        while( pos <= n ){
            bit[pos] = ( bit[pos] + val ) % mod ;  
            pos += pos&-pos ; 
        }
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // index compression 
    int curr = 1 ; 
    vector<pair<int,int>> pairs(n) ; 
    for( int i=0 ; i<n ; ++i ){
        pairs[i] = { arr[i] , i } ; 
    }
    sort( pairs.begin() , pairs.end() ) ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ pairs[i].second ] = curr ; 
        while( i+1<n && pairs[i+1].first == pairs[i].first ){
            i++ ; 
            arr[ pairs[i].second ] = curr ; 
        }
        curr++ ; 
    }
    BIT bit( curr ) ; 
    ll rs = 0 ;
    for( int i=0 ; i<n ; ++i ){
        ll prev = bit.get( arr[i] - 1 ) + 1 ; 
        rs = ( rs + prev ) % mod ; 
        bit.update( arr[i] , prev ) ;
    }
    cout << rs << '\n' ; 
    return 0;
}
