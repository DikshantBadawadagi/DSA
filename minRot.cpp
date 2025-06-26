#include <iostream>
#include <vector>
#include <string>
using namespace std;

string minimal_rotation(const string& s) {
    int n = s.size();
    string ss = s + s; // Concatenate string to itself
    vector<int> f(2 * n, -1);
    int k = 0;

    for (int j = 1; j < 2 * n; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && ss[j] != ss[k + i + 1]) {
            if (ss[j] < ss[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (i == -1 && ss[j] != ss[k + i + 1]) {
            if (ss[j] < ss[k + i + 1]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    return ss.substr(k, n);
}

int main() {
    string s;
    cin >> s;
    cout << minimal_rotation(s) << endl;
    return 0;
}
