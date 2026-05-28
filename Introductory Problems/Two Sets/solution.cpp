#include <iostream>
using namespace std;

int main() {
  // Fastio 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n % 4 != 0 && (n + 1) % 4 != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;

    if (n % 4 == 0) {
        int inter = n / 4;
        int left = 1;
        int right = n;
        int count = 0 ; 
        cout << inter * 2 << endl;
        while (left <= right && count != inter) {
            cout << left << " " << right << endl;
            left++;
            right--;
            count++ ; 
        }
        cout << inter * 2 << endl;
        while (left <= right) {
            cout << left << " " << right << endl;
            left++;
            right--;
        }
    } else {
        int inter = (n + 1) / 4;
        int left = 1;
        int right = n - 1;
        int count = 0 ; 
        cout << (inter - 1) * 2 + 1 << endl;
        while (left <= right && count != (inter-1)) {
            cout << left << " " << right << endl;
            left++;
            right--;
            count++ ; 
        }
        cout << n << endl;
        cout << inter * 2 << endl;
        while (left <= right) {
            cout << left << " " << right << endl;
            left++;
            right--;
        }
    }
  }

  return 0;
}
