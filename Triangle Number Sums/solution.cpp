#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;

unordered_map<ll,int> memo ; 
vector<ll> nums ; 

bool isTri( ll n ){
    ll num = 8*n+1 ; 
    ll s = sqrt(num) ; 
    return s*s == num ; 
}

int solve(ll n){
    if( memo.find(n) != memo.end() ){
        return memo[n] ; 
    }
    if( isTri(n) ){
        return memo[n] = 1; 
    }
    ll l = 0 ; 
    ll r = nums.size() - 1;
    while( l <= r ){
        ll curr = nums[l] + nums[r] ; 
        if( curr == n ){
            return memo[n] = 2 ;  
        }else if( curr < n ){
            l++ ; 
        }else if( curr > n ){
            r-- ;
        }
    }
    return memo[n] = 3 ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll curr = 1 ; 
    for(  ; curr*(curr+1)/2 <= 1e12 ; ++curr ){
        nums.push_back( curr*(curr+1)/2 ) ; 
    } 
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    
    return 0;
}