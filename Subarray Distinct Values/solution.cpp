#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ; 
using ll = long long ; 

int main(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    vector< pair<int,int> > pairs( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        pairs[i] = { arr[i] , i } ; 
    }
    sort( pairs.begin() , pairs.end() ) ; 
    int in = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ pairs[i].second ] = in ; 
        while( i + 1 < n && pairs[i].first == pairs[i+1].first ){
            i++ ; 
            arr[ pairs[i].second ] = in ; 
        }
        in++ ; 
    }
    ll rs = 0 ; 
    vector<int> f( in+1 , 0 ) ; 
    int start = 0 ; 
    int elements = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( f[ arr[i] ]++ == 0 ){
            elements++ ; 
        }
        if( elements > k ){
            while( f[ arr[start] ] != 1 ){
                f[ arr[start++] ]-- ; 
            }
            f[ arr[start++] ]-- ; 
            elements-- ; 
        }
        rs += i - start + 1 ; 
    }

    cout << rs << endl ; 
    return 0 ; 
}