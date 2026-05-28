#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

  
    bitset<1000000001> seenNumbers; // Range [-1e9, 1e9]
    int uniqueCount = 0;
    while (n--) {
        int x;
        cin >> x;
        if (!seenNumbers[x]) {
            seenNumbers[x] = 1;
            uniqueCount++;
        }
    }
    cout << uniqueCount << endl;

    return 0;
}
