#include <iostream>
#include <vector>
#include <queue>

using namespace std ; 
using ll = long long ; 


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n  ; cin >> n ; 
    vector< vector<int> > edges( n+1 ) ;
    for( int i=1 ; i<n ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        edges[a].push_back( b ) ; 
        edges[b].push_back( a ) ; 
    }
    vector<bool> isSeen( n+1 , false ) ; 
    queue<int> q ; 
    q.push( 1 ) ; 
    isSeen[1] = true ; 
    int far = 1 ; 
    while( !q.empty() ){
        int len = q.size() ; 
        for( int i=0 ; i<len ; ++i ){
            int curr = q.front() ; 
            far = curr ; 
            q.pop() ; 
            for( int j : edges[curr] ){
                if( !isSeen[j] ){
                    isSeen[j] = true ; 
                    q.push( j ) ; 
                }   
            }
        }
    }
    q.push( far ) ;
    for( int i=1 ; i<=n ; ++i ){
        isSeen[i] = false ; 
    }
    isSeen[far] = true ; 
    int diam = 0 ; 
    while( !q.empty() ){
        diam++ ; 
        int len = q.size() ; 
        for( int i=0 ; i<len ; ++i ){
            int curr = q.front() ; 
            far = curr ; 
            q.pop() ; 
            for( int j : edges[curr] ){
                if( !isSeen[j] ){
                    isSeen[j] = true ; 
                    q.push( j ) ; 
                }   
            }
        }
    }
    cout << diam-1 << endl ; 
    return 0 ; 
}