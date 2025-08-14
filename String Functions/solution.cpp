#include <iostream> 
#include <vector> 
#include <algorithm> 

using ll = long long ; 

using namespace std ; 

int main() {
    string s ; cin >> s ; 
    int n = (int) s.size() ; 
    // The Z Algorithm part
    vector<int> z(n) ; 
    z[0] = 0 ;
    int l = 0 , r = 0;  
    for( int i=1 ; i<n ; ++i ){
        if( i < r ){
            z[i] = min( r-i , z[i-l] ) ; 
        }
        while( i+z[i] < n && s[ i+z[i] ] == s[ z[i] ] ){
            z[i]++ ; 
        }
        if( i + z[i] > r ){
            l = i ; 
            r = i + z[i] ; 
        }
    }
    for( int i : z ){
        cout << i << " " ; 
    }
    cout << "\n" ; 
    // The KMP Algorithm Part
    vector<int> pi(n,0) ;
    for( int i=1 ; i<n ; ++i ){
        int j = pi[i-1] ; 
        while( j > 0 && s[i] != s[j] ){
            j = pi[j-1] ; 
        }
        if( s[i] == s[j] ){
            j++ ; 
        }
        pi[i] = j ;
    }
    for( int i=0 ; i<n ; ++i ){
        cout << pi[i] << '\n';  
    }


    return  0 ; 
}