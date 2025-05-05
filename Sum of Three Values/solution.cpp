#include <iostream>
#include <algorithm>
#include <vector>


using namespace std ; 
using  ll = long long ; 

int main(){
    int n ; cin >> n ;
    int x ; cin >> x ; 
    vector< pair<int , int> > arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int ai ; cin >> ai ; 
        arr[i] = { ai , i+1 } ; 
    }
    sort( arr.begin() , arr.end() ) ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=i+2 ; j<n ; ++j ){
            ll curr = (ll) arr[i].first + arr[j].first ; 
            if( curr > x ) break ; 
            int l = i+1 ; 
            int r = j-1 ;
            ll target = x - curr ;  
            while( l < r ){
                int mid = l + ( r - l + 1 )/2 ; 
                if( arr[mid].first <= target ){
                    l = mid ; 
                }else {
                    r = mid - 1 ; 
                }
            } 
            if( arr[l].first == target ){
                cout << arr[i].second << " " << arr[j].second << " " << arr[l].second << endl ; 
                return 0 ; 
            }
        }
    }

    cout << "IMPOSSIBLE" << endl ; 

    return  0 ; 
}