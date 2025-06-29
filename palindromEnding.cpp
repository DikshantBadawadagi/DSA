#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int P = 31;

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int mod_inverse(int a, int mod) {
    return mod_pow(a, mod - 2, mod);
}

int32_t main() {
    string s;
    cin >> s;
    int n = s.length();

    vector<int> res(n);

    int prefix_hash = 0, suffix_hash = 0;
    int power = 1;

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a' + 1;

        prefix_hash = (prefix_hash + c * power) % MOD;
        suffix_hash = (suffix_hash * P + c) % MOD;

        if (prefix_hash == suffix_hash) {
            res[i] = i + 1;  // Whole substring s[0..i] is palindrome
        } else {
            res[i] = res[i - 1];  // At least the previous palindrome length
            // Now check smaller palindromes ending at i
            for (int len = res[i - 1] + 1; len <= i + 1; len++) {
                bool is_palindrome = true;
                for (int l = i - len + 1, r = i; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (is_palindrome) {
                    res[i] = len;
                    break;
                }
            }
        }

        power = (power * P) % MOD;
    }

    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
