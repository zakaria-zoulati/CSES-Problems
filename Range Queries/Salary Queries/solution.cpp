#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

struct BIT {
    vector<int> tree ; 
    int n ; 

    BIT( int n ) : n(n) , tree(n+1,0) {} 

    void update( int idx , int delta ){
        while( idx <= n ){
            tree[idx] += delta ; 
            idx += idx & -idx ; 
        }
    }

    int query( int idx ){
        int ans = 0 ; 
        while( idx > 0 ){
            ans += tree[idx] ; 
            idx -= idx & -idx ; 
        }
        return ans ; 
    }

    int qrange( int l , int r ){
        return query( r ) - ( l > 1 ? query(l-1) : 0 ) ;  
    }

};  

void solve(){
    int n , q ; 
    cin >> n >> q ; 

    vector<int> salary(n+1);
    vector<int> vals ; 
    map<int,int> compress; 

    for( int i=1; i<=n ; ++i ){
        cin >> salary[i];
        vals.push_back(  salary[i] ) ; 
    }

    vector<char> queries(q);
    vector<pair<int,int>> qvals(q) ; 

    for( int i=0 ; i<q ; ++i ){
        cin >> queries[i]; 
        int a , b ; 
        cin >> a >> b ; 
        if( queries[i] == '!' ){
            vals.push_back( b );   
        }else {
            vals.push_back(a);
            vals.push_back(b); 
        }
        qvals[i] = { a , b } ; 
    }

    // coordinate compression 
    sort( all(vals) );
    vals.erase( unique( vals.begin() , vals.end() ) , vals.end() ) ; 

    for( int i=0 ; i<vals.size() ; ++i ){
        compress[ vals[i] ] = i+1;  
    }

    BIT bit( vals.size() ) ;

    for( int i=1 ; i<=n ; ++i ){
        bit.update( compress[ salary[i] ] , 1 ) ; 
    }

    for( int i=0 ; i<q ; ++i ){
        if( queries[i] == '!' ){    
            int k = qvals[i].first ;
            int v = qvals[i].second ;

            bit.update( compress[salary[k]] , -1 ) ; 

            salary[k] = v ; 

            bit.update( compress[v] , 1 ) ; 

        } else {
            auto [a,b] = qvals[i] ; 
            cout << bit.qrange( compress[a] , compress[b] ) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}