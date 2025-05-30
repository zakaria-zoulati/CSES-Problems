#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std ; 
using ll = long long ; 


int main(){
    int n ; cin >> n ; 
    vector< pair<int,int> > pairs( n ) ; 
    for( int i=0; i<n ; ++i ){
        int a ; cin >> a ; 
        int d ; cin >> d ; 
        pairs[i] = { a , d } ; 
    }
    sort( pairs.begin() , pairs.end() ) ; 
    ll rs = 0 ; 
    ll curr = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        curr += pairs[i].first ; 
        rs += pairs[i].second - curr ; 
    }
    cout << rs << endl ; 
    return 0 ; 
}