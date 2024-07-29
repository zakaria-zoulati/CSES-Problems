#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long n;
  cin >> n;
  cout << 0 << endl; 
  
  for (int i = 2; i <= n; ++i) {
    long long bn = i * i; // The total number of cases 
    long long initial = bn * (bn - 1) / 2;  
    long long  elements = i ; 
    while( elements >=3 ){
        if(elements == 3 ){
            initial -= 8 ; 
        }
        else if( elements==4 ){
            initial -= 24 ;
        }
        else {
            initial -= 8 ; //The Corners  
            initial -= 16 ; // The near Corners 
            initial -= (elements - 4)*4*4 ; // The Center elements 
        }
        elements -= 2 ; 
    }
    cout << initial << endl;
  }
  return 0;
}
