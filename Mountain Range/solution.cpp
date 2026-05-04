#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int> ; 
using vvi = vector<vi> ; 

struct Range {
    int h ; 
    int size ; 
    int pathlen ; 
};  

void solve(){
    int n ; cin >> n ; 
    vector<Range> ranges ; 
    vector<int> indexes ; 
    for( int i=0 ; i<n ; ++i ){
        int h ; cin >> h ; 
        indexes.push_back(i) ; 
        ranges.push_back( { h , 1 , 1 } ) ; 
    }    

    int bestpath = 0 ; 

    sort(
        indexes.begin() , 
        indexes.end() , 
        [&]( int i , int j ) { return ranges[i].h < ranges[j].h ; }
    ); 

    for( int ii=0 ; ii<n ; ++ii ){
        int i = indexes[ii] ;
        auto r = ranges[i] ; 
        int li = i ; 
        while( li > 0 && ranges[li-1].h < r.h ){
            auto tr = ranges[li-1] ; 
            if( tr.pathlen >= r.pathlen ){
                r.pathlen = tr.pathlen + 1 ;  
            }
            li -= tr.size ; 
        } 
        int ri = i ; 
        while( ri < n-1 && ranges[ri+1].h < r.h ){
            auto tr = ranges[ri+1] ; 
            if( tr.pathlen >= r.pathlen ){
                r.pathlen = tr.pathlen + 1 ; 
            }
            ri += tr.size ; 
        }
        r.size = ri -li + 1 ; 
        if( r.pathlen > bestpath ){
            bestpath = r.pathlen ; 
        }
        ranges[li] = ranges[ri] = r ; 
    }

    cout << bestpath << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}