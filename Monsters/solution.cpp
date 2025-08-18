#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;

struct State {
    ll d ; 
    int i , j ;
    bool operator>(const State& other ) const {
        return d > other.d ; 
    }
};

bool valid( int i , int j , vector<vector<ll>> &dist_m , ll d ){
    return dist_m[i][j] > d ;
}

string getDir( pair<int,int> &s , pair<int,int> &e ){
    if( e.first == s.first + 1 ){
        return "D" ; 
    }
    if( e.first == s.first - 1 ){
        return "U" ; 
    }
    if( e.second == s.second + 1 ){
        return "R" ; 
    } 
    return "L" ; 
} 

void solve( int i , int j , map< pair<int,int> , pair<int,int>> &parent ){
   pair<int,int> curr = { i , j }; 
   string rs = "" ; 
   while( parent.count(curr) && parent[ curr ].second != -1 ){
        rs += getDir( parent[curr] , curr ) ; 
        curr = parent[ curr ] ; 
   }
   reverse( rs.begin()  , rs.end() ) ; 
   cout << rs.size() << '\n' ; 
   cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ; 
    cin >> n >> m ; 

    vector<string> grid( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> grid[i] ; 
    }
    pair<int,int> s ; 
    vector< pair<int,int> > monsters ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            if( grid[i][j] == 'A' ){
                s = { i , j } ; 
            }else if(  grid[i][j] == 'M' ){
                monsters.push_back( {i,j} ) ; 
            }
        }
    }

    priority_queue<State,vector<State> , greater<State>> pq ;
    vector<vector<ll>> dist_m( n , vector<ll>( m , LLONG_MAX ) ) ;   
    for( auto [i,j] : monsters ){
        pq.push( { 0 , i , j } ) ; 
    }
    while( !pq.empty() ){
        auto [ d , i , j ] = pq.top() ; 
        pq.pop() ; 
        if( dist_m[i][j] <= d ) continue ; 
        dist_m[i][j] = d; 
        if( i+1<n && grid[i+1][j] != '#' ){
            pq.push( { d+1 , i+1 , j } ) ; 
        }
        if( j+1<m && grid[i][j+1] != '#' ){
            pq.push( { d+1 , i , j+1 } ) ; 
        }
        if( i>0 && grid[i-1][j] != '#' ){
            pq.push( { d+1 , i-1 , j } ) ; 
        }
        if( j>0 && grid[i][j-1] != '#' ){
            pq.push( { d+1 , i, j-1 } ) ; 
        }
    }

    vector<vector<ll>> dist_user( n , vector<ll>( m , LLONG_MAX ) ) ; 
    map<pair<int,int> , pair<int,int>> parent ; 
    parent[s] = { -1 , -1 } ; 
    pq.push( { 0 , s.first , s.second } ) ; 
    vector<pair<int,int>> dirs ; 
    dirs.push_back( {0,1} ) ; 
    dirs.push_back( {0,-1} ) ; 
    dirs.push_back( {-1,0} ) ; 
    dirs.push_back( {1,0} ) ; 

    while( !pq.empty() ){
        auto [ d , i , j ] = pq.top() ; 
        pq.pop() ; 
        if( dist_user[i][j] < d  ) continue ;  
        dist_user[i][j] = d; 
        for( auto [ di , dj ] : dirs ){
            int x = i + di ; 
            int y = j + dj ; 
            if( x>=0 && y>=0 && x<n && y<m && grid[x][y] != '#' && valid( x,y,dist_m,d+1 ) ){
                if( d+1 < dist_user[x][y] ){
                    dist_user[x][y] = d+1 ; 
                    parent[ {x,y} ] = {i,j} ; 
                    pq.push( { d+1 , x , y } ) ; 
                }
            }
        }
    }

    for( int i=0 ; i<n ; ++i ){
        if( dist_user[i][0] !=  LLONG_MAX){
            cout << "YES" << '\n' ; 
            solve( i , 0 , parent ) ; 
            return 0 ; 
        }
        if( dist_user[i][m-1] != LLONG_MAX ){
            cout << "YES" << '\n' ; 
            solve( i , m-1 , parent ) ; 
            return 0 ; 
        }
    }
    for( int i=0 ; i<m ; ++i ){
        if( dist_user[0][i] != LLONG_MAX ){
            cout << "YES" << '\n' ; 
            solve( 0, i , parent ) ; 
            return 0 ; 
        }
        if( dist_user[n-1][i] != LLONG_MAX ){
            cout << "YES" << '\n' ; 
            solve(  n-1 , i, parent ) ; 
            return 0 ; 
        }
    }
    cout << "NO" << '\n' ; 

    return 0;
}
