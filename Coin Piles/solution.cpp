#include <iostream> 
using namespace std ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t ; 
    cin>> t ; 
    for( int p=0 ; p<t ; ++p ){
        long long  a , b ; 
        cin >> a >>  b ; 
        long long j= 2*b-a; 
        long long k = 2*a -b ; 
        if( j >= 0 && k>=0 && j%3 == 0 && k%3 == 0  ){
            cout << "YES" << "\n" ;
        }else {
            cout << "NO" << "\n" ; 
        }
    }
    return 0 ;
}