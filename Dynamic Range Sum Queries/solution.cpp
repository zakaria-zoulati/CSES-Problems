#include <iostream>
#include <vector>
#include <algorithm>


using namespace std ; 
using ll = long long ; 

struct FenwickTree {
    vector<ll> bit; 
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll rs = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            rs += bit[r];
        return rs ;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , q ; 
    cin >> n >> q ;
    
    vector<ll> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    FenwickTree bit( arr ) ; 

    while( q-- ){
        int u ; cin >> u ; 
        ll a , b ; 
        cin >> a >> b ; 

        if( u == 1 ){
            ll diff = b - arr[a-1] ; 
            arr[a-1] = b ; 
            bit.add( a-1 , diff ) ; 
        }else {
            ll rs = -1 ; 
            if( a == 1 ){
                rs = bit.sum( b-1 ) ; 
            }else {
                rs = bit.sum( a - 1 , b - 1 ) ; 
            }
            cout << rs << '\n' ; 
        }
    }
    return 0 ; 
}