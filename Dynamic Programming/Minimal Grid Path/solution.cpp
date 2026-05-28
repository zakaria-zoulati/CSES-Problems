#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int,int> ; 



void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    int len = 2*(n-1) + 1 ; 
    string ans( len , '_' ) ;

    int curr = 0 ; 
    queue<pii> q ; 
    vector<vector<int>> seen( n , vector<int>( n , false ) ) ; 

    q.push( {0,0} ) ; 
    while( !q.empty() ){
        int l = q.size() ; 
        char best = 'z' ; 
        vector<pii> nodes ; 
        while( l-- ){
            pii node = q.front() ; 
            q.pop() ; 
            best = min( best , grid[ node.first ][ node.second ]  ) ; 
            nodes.push_back( node ) ; 
        }

        for( pii node : nodes ){
            if( grid[ node.first ][ node.second ] == best ){
                if( node.first + 1 < n && !seen[ node.first+1 ][ node.second ] ){
                    q.push( { node.first + 1 , node.second } ) ; 
                    seen[ node.first+1 ][ node.second ] = true ; 
                }
                if( node.second + 1 < n && !seen[ node.first ][ node.second + 1 ] ){
                    q.push( { node.first , node.second + 1 } ) ; 
                    seen[ node.first ][ node.second + 1 ] = true ; 
                }
            }
        }

        ans[curr++] = best ; 
    }

    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}