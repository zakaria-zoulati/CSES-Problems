#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1'000'000;
    vector<int> freq(MAX + 1, 0);
    int n;
    cin >> n;

    int maxNum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        freq[num]++;
        maxNum = max(maxNum, num);
    }

    for (int i = maxNum; i >= 1; --i) {
        int cnt = 0;
        for (int j = i; j <= MAX; j += i) {
            cnt += freq[j];
            if (cnt >= 2) break;
        }
        if (cnt >= 2) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "1\n";
    return 0;
}
