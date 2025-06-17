#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long res = 1; // the smallest sum we can't create yet
    for(int i = 0; i < n; i++) {
        if(coins[i] > res) break;
        res += coins[i];
    }

    cout << res << endl;
    return 0;
}
