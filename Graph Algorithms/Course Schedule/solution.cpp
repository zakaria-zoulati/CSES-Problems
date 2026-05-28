#include <iostream> 
#include <vector>
#include <queue>

using namespace std  ;



int main(){
    int n , m ; 
    cin >> n >> m ; 
    vector<int> indegree( n+1 , 0 ) ; 
    vector<vector<int>> edges( n+1  ) ; 
    while( m-- ){
        int a  , b ; 
        cin >> a >> b ; 
        edges[a].push_back(b) ; 
        indegree[b]++ ; 
    }
    vector<int> result ; 

    queue<int> q ; 
    for( int i=1 ; i<=n ; ++i ){
        if( indegree[i] == 0 ){
            q.push( i ) ; 
        }
    }

    while( !q.empty() ){
        int curr = q.front() ; 
        result.push_back(curr) ; 
        q.pop() ; 
        for( int i : edges[curr]  ){
            --indegree[i] ; 
            if( indegree[i] == 0 ){
                q.push( i ) ; 
            }
        }
    }




    if( result.size() == n ){
        for( int i=0 ; i<n ; ++i ){
            cout << result[i] << " " ; 
        }
    }else {
        cout << "IMPOSSIBLE" << endl ; 
    }
    return 0 ; 
}