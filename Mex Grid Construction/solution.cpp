#include <iostream>
#include <vector>
#include <set>

using namespace std ; 

int main(){
    int n ; cin >> n ; 
    vector<vector<int>> grid( n , vector<int>(n) ) ; 
    vector< set<int>> row(n) ; 
    vector< set<int>> col(n) ;     
    for( int i=0 ; i<n ; ++i ){
        grid[0][i] = i ;
        grid[i][0] = i ;  
        row[i].insert(i) ; 
        col[i].insert(i) ; 
    }

    for( int j=1 ; j<n ; ++j ){
        for( int i=1 ; i<n ; ++i ){
            int ele = 0 ; 
            while( row[i].count(ele) || col[j].count(ele) ){
                ele++ ; 
            }
            grid[i][j] = ele ; 
            row[i].insert(ele) ; 
            col[j].insert(ele) ; 
        }
    }

    
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<n ; ++j ){
            cout << grid[i][j] << " " ; 
        }
        cout << '\n' ; 
    }

    return 0;
}