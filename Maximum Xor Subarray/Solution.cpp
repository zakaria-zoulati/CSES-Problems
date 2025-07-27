#include <iostream>
#include <vector>

using namespace std ; 
using ll = long long ; 

struct Trie {
    Trie* child[2] = { nullptr , nullptr } ; 
};

void insert( Trie* root , ll num ){
    Trie* curr = root ; 
    for( int i=30 ; i>=0 ; --i ){
        int ibit = ( num >> i ) & 1 ; 
        if( !curr->child[ibit] ){
            curr->child[ibit] = new Trie() ; 
        }
        curr = curr->child[ibit] ; 
    }
}

ll getMax( Trie* root , ll num ){
    // ll curr = 0 ; 
    Trie* curr = root ; 
    ll rs = 0 ;
    for( int i=30 ; i>=0 ; --i ){
        int ibit = ( num >> i ) & 1 ; 
        if( curr->child[1-ibit] ){
            rs |= ( 1 << i ) ; 
            curr = curr->child[1-ibit] ; 
        }else{
            curr = curr->child[ibit] ; 
        }
    }   
    return rs ; 
}

int main(){
    int n ; cin >> n ;
    vector<ll> arr(n) ; 
    Trie* root = new Trie() ; 
    insert( root , 0 ); 
    ll rs = 0 ; 
    ll maxXor = 0 ; 
    ll prefix= 0 ; 
    for( int i=0  ; i<n ; ++i ){
        ll a ; cin >> a ; 
        prefix ^= a ; 
        maxXor = max( maxXor , getMax( root , prefix ) ) ; 
        insert( root , prefix ) ; 
        rs = max( rs , maxXor ) ; 
    }
    cout << rs << '\n' ; 

    return 0;
}