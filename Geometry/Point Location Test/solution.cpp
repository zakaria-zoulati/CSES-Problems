#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 

        ll crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        
        if (crossProduct < 0)
            cout << "RIGHT" << endl;
        else if (crossProduct > 0)
            cout << "LEFT" << endl;
        else
            cout << "TOUCH" << endl;
        
    }

    return 0;
}
