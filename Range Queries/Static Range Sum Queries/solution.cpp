#include <iostream> 
#include <vector>

using namespace std ; 
using ll = long long ; 


int main(){
    int n , q ; 
    cin >> n >> q ; 
    vector<ll> pref( n + 1  ) ; 
    pref[0] = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        int ai ;  cin >> ai ; 
        pref[i+1] = pref[i] + ai ; 
    }
    while( q-- ){
        int a , b ; 
        cin >> a >> b ; 
        ll rs = pref[b] - pref[a-1] ; 
        cout << rs << endl ; 
    }


    return 0 ; 
}
