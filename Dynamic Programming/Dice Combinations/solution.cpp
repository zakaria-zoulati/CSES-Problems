#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mod = 1e9 + 7;
    vector<int> arr(n + 1, 0); 

    for( int i=1 ; i<=6  ; ++i ){
        arr[i] = 1 ; 
    }

    for(int i=2 ; i<=n ; ++i){
        for( int j=1 ; j<=6 && i-j >=1 ; ++j ){
            arr[i] = ( arr[i] + arr[i-j]  ) % mod ;  
        }
    }

    cout << arr[n] << "\n" ; 
    
    return 0;
}
