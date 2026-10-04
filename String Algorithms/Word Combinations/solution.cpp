#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7 ;

struct Trie{
    vector<Trie*> childs ; 
    bool flag ;

    Trie() : childs(26) , flag(false) {} 

    void update( string &s ){
        Trie* curr = this ;
        for( int i=s.size()-1 ; i>=0 ; --i ){
            int c = s[i] - 'a' ; 
            if( curr->childs[c] == nullptr ){
                curr->childs[c] = new Trie() ; 
            }
            curr = curr->childs[c] ; 
        }   
        curr->flag = true ; 
    }

    ll solve( string &s  , int idx , vector<ll> &dp ){
        ll ans = 0 ;
        Trie* curr = this ; 
        for( int i=idx ; i>=0 ; --i ){
            int c = s[i] - 'a' ; 
            if( curr->childs[c] == nullptr ){
                break ; 
            }
            curr = curr->childs[c] ; 
            if( curr->flag ){
                ans += ( i > 0 ? dp[i-1] : 1 ) ; 
            }
        }
        return ans % mod ; 
    }
};

void solve(){
    string s; cin >> s ;
    int n = s.size() ; 
    int k ; cin >> k ; 

    Trie root ; 

    while( k-- ){
        string w ; cin >> w ; 
        root.update(w) ; 
    }


    vector<ll> dp( n , 0 ) ; 

    for( int i=0 ; i<n ; ++i ){
        dp[i] = root.solve( s , i , dp ) ; 
    }

    cout << dp[n-1] << '\n' ; 
}


int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}