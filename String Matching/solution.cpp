#include <iostream>
#include <vector>

using namespace std ; 

int main( ) {
    string s , t ; 
    cin >> s >> t ; 
    int n = s.size() ; 
    int m = t.size() ;
    string inter = t + "$" + s ; 
    int len = inter.size() ; 
    vector<int> z( len , 0) ;
    int l=0 , r=0 ;  
    for( int i=1 ; i<len ; ++i ){
        if( i < r ){
            z[i] = min( r - i , z[i-l] ) ; 
        }
        while( i + z[i] < len && inter[ i + z[i] ] == inter[ z[i] ] ){
            z[i]++ ;
        }
        if( i+z[i] > r ){
            l = i ; 
            r = i + z[i] ; 
        }
    }

    int count = 0 ; 
    for( int i=m+1 ; i<len ; ++i ){
        if( z[i] == m ){
            count++  ;
        }
    }
    cout << count << endl ; 
    return 0 ; 
}