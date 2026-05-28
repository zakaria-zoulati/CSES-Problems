#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector< pair<int,int>> helper( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        helper[i] = { arr[i] , i } ; 
    }
    sort( helper.begin() , helper.end() ) ; 
    int in = 0  ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ helper[i].second ] = in ; 
        while( i+1 < n && helper[i+1].first == helper[i].first ){
            i++ ;  
            arr[ helper[i].second ] = in ; 
        }
        in++ ; 
    }
    int rs = 1 ; 
    vector<int> f( in , 0 ) ;
    int start = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        while( f[ arr[i] ] > 0 ){
            f[ arr[start++] ]-- ; 
        }
        f[ arr[i] ]++  ;
        rs = max( rs , i - start +1 ) ; 
    }


    cout << rs << endl;
    return 0;
}
