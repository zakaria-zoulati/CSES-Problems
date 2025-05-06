#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll x;
    cin >> x;
    map<ll, int> mp;
    mp[0] = 1;
    ll curr = 0;
    ll rs = 0;
    for (int i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        curr += ai;
        rs += mp[curr - x];
        mp[curr]++;
    }
    cout << rs << '\n';
    return 0;
}
