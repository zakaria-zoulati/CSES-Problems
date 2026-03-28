#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void compute( vector<vector<int>> &edges , vector<int> &subs ){
    stack<int> st ; 
    vector<int> order ; 
    st.push(1) ; 
    while( !st.empty() ){
        int u = st.top() ; st.pop() ; 
        order.push_back(u) ; 
        for( int c : edges[u] ) st.push(c) ; 
    }
    for( int i=order.size()-1 ; i>=0 ; --i ){
        int u = order[i] ; 
        for( int c : edges[u] ){
            subs[u] += 1 + subs[c] ; 
        }
    }

}

void solve(){
    int n ; cin >> n ; 
    vector<vector<int>> edges( n+1 ) ; 
    for( int i=2 ; i<=n ; ++i ){
        int v ; cin >> v ; 
        edges[v].push_back( i ) ; 
    }
    vector<int> subs( n+1 , 0 ) ;
    
    compute( edges , subs ) ;
    
    for( int i=1 ; i<=n ; ++i ){
        cout << subs[i] << " " ; 
    }
}
int main() {
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}