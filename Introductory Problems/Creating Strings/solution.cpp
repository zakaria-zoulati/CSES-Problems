#include <iostream> 
#include <vector>
#include <unordered_set>
#include <string>

using namespace std ; 

vector<string> set ; 


void backtrack( vector<int> &chars , int curr ,  int in , int n , string &s ){
   if( in == n ){
      set.push_back(s)  ; 
      return ; 
   }
   for( int i=curr ; i<26 ; ++i ){
     if( chars[i] > 0  ){
        chars[i]-- ; 
        s[in] = (char) ( 'a' + i ) ;  
        backtrack( chars , curr , in+1 , n , s ) ; 
        chars[i]++ ; 
     }
   }
}


int main( ){
   string s ; cin >> s ; 
   int n = s.size() ; 
   int count = 0 ; 
   vector<int> chars( 26 , 0 ) ;  
   for( char c : s ){
      chars[ c - 'a' ]++ ; 
   }
   string curr( n , '-' ) ; 
   backtrack(  chars , 0 ,  0 , n , curr ) ; 

   cout << set.size()  << endl ; 
   for( string s : set ){
       cout << s << endl ; 
   }

    return 0 ; 
}


