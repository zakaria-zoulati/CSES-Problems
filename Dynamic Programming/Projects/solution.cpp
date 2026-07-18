#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n ; cin >> n ; 
    vector<tuple<int,int,int>> ps(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int a , b , c ; 
        cin >> a >> b >> c ; 
        ps[i] = { a,b,c };
    }    

    vector<int> vals ; 
    for( int i=0 ; i<n ; ++i ){
        vals.push_back( get<0>(ps[i]) );
        vals.push_back( get<1>(ps[i]) );
    }

    sort( all(vals) ) ;
    map<int,int> mapper; 
    int curr = 1 ; 
    for( int i=0 ; i<vals.size() ; ++i ){
        mapper[vals[i]] = curr ; 
        while( i+1<vals.size() && vals[i+1] == vals[i] ){
            i++ ; 
        }
        curr++ ; 
    }

    
    for( int i=0 ; i<n ; ++i ){
        get<0>(ps[i]) = mapper[ get<0>(ps[i]) ] ;  
        get<1>(ps[i]) = mapper[ get<1>(ps[i]) ] ;  
    }

    vector<vector<pair<int,int>>> segments(2*n+1 ) ; 
    
    for( int i=0 ; i<n ; ++i ){
        segments[get<1>(ps[i])].push_back(  { get<0>(ps[i])  , get<2>(ps[i]) }  ) ;  
    }


    vector<ll> dp( 2*n+2 , 0 ) ;


    for( int i=1 ; i<=2*n ; ++i ){
        dp[i] = dp[i-1] ; 

        for( auto &[a,c] : segments[i] ){
            dp[i] = max( dp[i] , c + dp[a-1] ) ; 
        }
    }


    cout << dp[2*n] << "\n" ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}