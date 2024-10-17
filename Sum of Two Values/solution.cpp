#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    int x; 
    cin >> x;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first; // value
        arr[i].second = i + 1; // original index (1-based)
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;
    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        if (sum < x) {
            ++left;
        } else if (sum > x) {
            --right;
        } else {
            cout << arr[left].second << " " << arr[right].second << "\n"; // Print original indices
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
