#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateZ(string &s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int l = 0, r = 0;

    for(int i = 1; i < n; i++) {
        if(i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if(i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    string a, b;
    cin >> a >> b;

    string combined = b + "$" + a;
    vector<int> Z = calculateZ(combined);

    int count = 0;
    int b_len = b.size();
    for(int i = b_len + 1; i < Z.size(); i++) {
        if(Z[i] == b_len) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
