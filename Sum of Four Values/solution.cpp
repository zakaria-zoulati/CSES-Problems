#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        arr[i] = {val, i + 1};
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 3; j < n; ++j) {
            int target = x - arr[i].first - arr[j].first;
            if( target < 2 ) continue ; 
            int l = i+1, r = j-1;
            while (l < r) {
                int sum = arr[l].first + arr[r].first;
                if (sum == target) {
                    cout << arr[i].second << " " << arr[j].second << " "
                         << arr[l].second << " " << arr[r].second << endl;
                    return 0;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
