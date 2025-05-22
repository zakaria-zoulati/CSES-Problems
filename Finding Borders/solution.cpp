#include <iostream> 
#include <vector>

using namespace std ; 
using ll = long long ; 


int main(){
    string s ; cin >> s ; 
    int n = s.size() ; 
    int l = 0 , r = 0 ; 
    vector<int> z( n , 0 ) ; 
    for( int i=1 ; i<n ; ++i ){
        if( i < r ){
            z[i] = min(  z[i-l]  ,r - i ) ; 
        }
        while( i+z[i]<n && s[ z[i] ] == s[ z[i] + i ] ){
            z[i]++ ; 
        }
        if( i + z[i] > r ){
            l = i ; 
            r = i + z[i] ; 
        }
    }
    for( int i=n-1 ; i>=1 ; --i ){
        if( z[i] + i == n ){
            cout << z[i] << " "  ; 
        }
    }


    return 0 ; 
}