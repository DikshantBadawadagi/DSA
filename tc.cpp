#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >>n>>s;
        int one = 0;
        for (char c : s) {
            if (c == '1') one++;
        }
        int tot = one * (n - 1)+(n - one);
        cout<<tot<<endl;
    }
    return 0;
}