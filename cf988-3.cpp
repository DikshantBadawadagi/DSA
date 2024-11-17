#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n < 5) {
            cout << -1 << endl; 
            continue;
        }

        if (n == 5) {
            cout << "1 3 5 4 2" << endl;
            continue;
        }
        vector<int> evens, odds;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                evens.push_back(i);
            else
                odds.push_back(i);
        }
        vector<int> result;
        for (int odd : odds) {
            if (odd != 1 && odd != 3 && odd != 5) {
                result.push_back(odd);
            }
        }
        result.push_back(1);
        result.push_back(3);
        result.push_back(5);
        result.push_back(4);
        result.push_back(2);
        for (int even : evens) {
            if (even != 4 && even != 2) {
                result.push_back(even);
            }
        }

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
