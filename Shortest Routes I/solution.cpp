#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <utility>

using namespace std ; 
using ll = long long ; 

int main(){
    int n , m  ; 
    cin >> n >> m ; 
    vector<vector< pair<int,int> >> edges( n+1 ) ; 
    while( m-- ){
        int u , v , c ; 
        cin >> u >> v >> c ; 
        edges[u].push_back( {v,c} ) ; 
    }
    vector<ll> dist( n+1 , LLONG_MAX ) ;
    priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<  pair<ll,int>> > pq ; 
    pq.push( {0,1} ) ; 
    while( !pq.empty() ){
        auto [ d , u ] = pq.top() ; 
        pq.pop() ; 
        if( d >= dist[u] ) continue ; 
        dist[u] = d ; 
        for( auto &[v,c] : edges[u] ){
            pq.push( { c + d , v } ) ; 
        }
    } 
    for( int i=1 ; i<=n ; ++i ){
        cout << dist[i] << " "  ; 
    }
    return 0 ; 
}