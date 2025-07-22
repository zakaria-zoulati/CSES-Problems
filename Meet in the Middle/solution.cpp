#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int mid = n / 2;

    vector<ll> left_sums;
    int len1 = 1 << mid;
    for (int i = 0; i < len1; ++i) {
        ll curr = 0;
        for (int j = 0; j < mid; ++j) {
            if ((i >> j) & 1) {
                curr += arr[j];
            }
        }
        if (curr <= x) {
            left_sums.push_back(curr);
        }
    }
    sort(left_sums.begin(), left_sums.end());

    ll result = 0;
    int len2 = 1 << (n - mid);
    for (int i = 0; i < len2; ++i) {
        ll curr = 0;
        for (int j = 0; j < n - mid; ++j) {
            if ((i >> j) & 1) {
                curr += arr[j + mid];
            }
        }
        if (curr <= x) {
            ll target = x - curr;
            result += upper_bound(left_sums.begin(), left_sums.end(), target) - lower_bound(left_sums.begin(), left_sums.end(), target) ; 
        }
    }

    cout << result << '\n';
    return 0;
}