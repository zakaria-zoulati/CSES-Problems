#include <iostream>
#include <stack>
#include <utility>

using namespace std ;


int main(){
    int n ; cin >> n ; 
    stack< pair<int,int> > s ;    
    for( int i=0 ; i<n ; ++i ){ 
        int a ; cin >> a ;
        while( !s.empty() && s.top().first >= a ){
            s.pop() ; 
        }
        if( s.empty() ){
            cout << 0 << " "  ; 
        }else {
            cout << s.top().second << " " ; 
        }
        s.push( { a , i+1 } ) ; 
    }

    return 0 ;
}