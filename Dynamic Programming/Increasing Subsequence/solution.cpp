#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTreeMax {
    vector<int> bit;
    int n;
    const int INF = (int)-1e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n + 1, INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, int>> map(n);
    for (int i = 0; i < n; ++i) {
        map[i] = {arr[i], i};
    }

    sort(map.begin(), map.end());
    int in = 0;
    arr[map[0].second] = in;

    for (int i = 1; i < n; ++i) {
        if (map[i].first != map[i - 1].first) in++;
        arr[map[i].second] = in;
    }

    FenwickTreeMax ft(in + 1);
    for (int i = 0; i < n; ++i) {
        int curr = arr[i];
        if (curr == 0) {
            ft.update(0, 1);
        } else {
            int prev = ft.getmax(curr - 1);
            prev = max(prev, 0);
            ft.update(curr, prev + 1);
        }
    }

    cout << ft.getmax(in) << endl;
    return 0;
}
