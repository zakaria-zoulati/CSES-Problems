#include <iostream>
#include <vector>


using namespace std ; 
using ll = long long ;


int div( int n  ){
    if( n % 2 == 0 ){
        return 2 ; 
    }
    if( n % 3 == 0 ){
        return 3 ; 
    }
    ll i=5 ; 
    while( i*i<=n ){
        if( n % i == 0 ){
            return  i ; 
        }
        if( n % (i+2) == 0 ){
            return i + 2 ; 
        }
        i += 6 ; 
    }
    return -1 ; 
}


int main(){
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    vector<int> divs( 1'000'001 ) ;
    divs[1] = 1 ; 
    for( int i=2 ; i<1'000'001 ; ++i ){
        int divisor = div(i) ; 
        if( divisor == -1 ){
            divs[i] = 2 ; 
        }else {
            int occ = 0 ; 
            int num = i ; 
            while( num % divisor == 0 ){
                occ++  ;
                num /= divisor ; 
            }
            divs[i] = ( occ + 1 )* divs[num] ;
        }
    }
    int n ; cin >> n ;
    while( n-- ){
        int x ; cin >> x ; 
        cout << divs[x] << endl ; 
    }
    return  0 ; 
}