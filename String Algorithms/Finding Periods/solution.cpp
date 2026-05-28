#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> z(n, 0);
    vector<int> output; 
    int l = 0, r = 0;
 
    for (ll i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i % n && i + z[i] == n) {
            output.push_back(i); 
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
 
    output.push_back(n); 
 
    for (int x : output) {
        cout << x << " ";
    }
 
    return 0;
}
