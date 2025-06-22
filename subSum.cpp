#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    long long sum = 0;
    int cnt = 0;

    while (end < n) {
        sum += arr[end];

        while (sum > x) {
            sum -= arr[start];
            start++;
        }

        if (sum == x) {
            cnt++;
        }

        end++;
    }

    cout << cnt << endl;
    return 0;
}
