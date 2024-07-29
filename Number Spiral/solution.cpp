#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        long long x, y;
        cin >> x >> y;

        long long inter = max(x, y);
        long long rs = 0;

        if (inter % 2 == 1) {
            rs = (inter - 1) * (inter - 1);
            rs += y;
            rs += (inter - x);
        } else {
            rs = (inter - 1) * (inter - 1);
            rs += x;
            rs += (inter - y);
        }

        cout << rs << endl;
    }

    return 0;
}
