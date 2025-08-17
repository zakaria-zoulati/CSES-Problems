#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <utility>

using namespace std ; 
using ll = long long ; 

struct State{
    ll dist ; 
    int node , state ; 
    bool operator>( const State &other ) const {
        return dist > other.dist ;
    }
};


int main(){
    int n , m  ; 
    cin >> n >> m ; 
    vector<vector< pair<int,int> >> edges( n+1 ) ; 
    while( m-- ){
        int u , v , c ; 
        cin >> u >> v >> c ; 
        edges[u].push_back( {v,c} ) ; 
    }
    vector<vector<ll>> dist( n+1 , vector<ll>(2,LLONG_MAX) ) ; 
    priority_queue<State,vector<State> , greater<State>> pq ; 
    pq.push( { 0 , 1 , 0 } ) ; 
    while( !pq.empty() ){
        auto [ d , u , s ] = pq.top() ; 
        pq.pop() ; 
        if( dist[u][s] <= d ) continue ; 
        dist[u][s] = d ;
        for( auto &[v,c] : edges[u] ){
            pq.push( { d + c , v , s } ) ;
            if( !s ){
                pq.push( { d + c/2 , v , 1 } ) ; 
            } 
        }
    }
    cout << min( dist[n][0] , dist[n][1] ) << '\n' ; 
    return 0 ; 
}