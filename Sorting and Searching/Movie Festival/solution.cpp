#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ; 
using ll = long long ; 


int main(){
    int n ; cin >> n ; 
    vector< pair<int,int>> intervals( n ) ;
    for( int i=0 ; i<n ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        intervals[i] = {b,a} ; 
    }
    sort( intervals.begin() , intervals.end() ) ; 
    int prev = -1 ; 
    int rs = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        if( intervals[i].second >= prev ){
            rs++ ; 
            prev = intervals[i].first ; 
        }
    }

    cout << rs << endl ; 

    return 0 ; 
}