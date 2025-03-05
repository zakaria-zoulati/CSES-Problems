#include <iostream> 
#include <vector>
#include <climits>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; 
    int x; cin >> x; 
    vector<int> arr(x + 1, INT_MAX - 1 );
    arr[0] = 0; 

    while (n--) {
        int a; cin >> a; 
        for( int i=a ; i<=x ; ++i ){
            arr[i] = min( arr[i] , arr[i-a] + 1 ) ; 
        }
    }
    cout << ((arr[x] == INT_MAX -1 ) ? -1 : arr[x]);  
    return 0;
}