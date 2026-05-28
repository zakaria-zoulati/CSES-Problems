#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std ; 
using ll = long long ; 

int main(){
    string s ; cin >> s ; 
    int n = s.size() ; 
    map<char,int> m ; 
    m['A'] = 0 ; 
    m['C'] = 1 ; 
    m['G'] = 2 ; 
    m['T'] = 3 ; 
    map<int,char> m2; 
    m2[0] ='A' ; 
    m2[1] = 'C' ; 
    m2[2] = 'G' ;
    m2[3] = 'T' ; 

    vector<vector<int>> arr( n+1 , vector<int>(4,n) ) ; 
    for( int i=n-1 ; i>=0 ; --i ){
        for( int j=0 ; j<4 ; ++j ){
            arr[i][j] = arr[i+1][j] ;
        }
        arr[i][ m[s[i]] ] = i ; 
    }
    
    int curr = -1; 
    string rs = "" ; 
    while( curr < n ){
        curr++ ;
        for( int j=0; j<4 ; ++j ){
            if( arr[curr][j] == n ){
                rs += m2[j] ;
                cout << rs << '\n'; 
                return 0 ;  
            }
        }
        int next = curr ; 
        for( int j=0 ; j<4 ; ++j ){
            next = max( next , arr[curr][j] ) ; 
        }
        curr = next ; 
        rs += s[curr] ; 
    }
    cout << rs << '\n' ; 
    return 0 ; 
}