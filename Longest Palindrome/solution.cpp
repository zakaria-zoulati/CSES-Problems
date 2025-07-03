#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    string curr = "#";
    for (auto c : s) {
        curr += c;
        curr += "#";
    }

    int len = curr.size();
    vector<int> p(len, 0);

    int l = 0, r = 0;

    for (int i = 0; i < len; ++i) {
        if (i < r)
            p[i] = min(r - i, p[l + (r - i)]);
        else
            p[i] = 0;
            
        while (i + p[i] + 1 < len && i - p[i] - 1 >= 0 && curr[i + p[i] + 1] == curr[i - p[i] - 1])
            ++p[i];

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    int rs = 0, in = 0;

    for (int i = 0; i < len; ++i) {
        if (p[i] > rs) {
            rs = p[i];
            in = (i - p[i]) / 2;
        }
    }

    string res = s.substr(in, rs);
    cout << res << '\n';

    return 0;
}
