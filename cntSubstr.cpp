#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;
const int ALPHABET = 26;

int main() {
    int n; // Length of final string
    string pattern; // The pattern to match
    cin >> n >> pattern;
    int m = pattern.size();

    // Step 1: Build prefix function (KMP failure function)
    vector<int> prefix(m, 0);
    for (int i = 1; i < m; i++) {
        int j = prefix[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefix[i] = j;
    }

    // Step 2: Build the transition table for automaton
    // next_state[state][char] tells where we go if we are at state 'state' and read character 'char'
    vector<vector<int>> next_state(m + 1, vector<int>(ALPHABET, 0));
    for (int state = 0; state <= m; state++) {
        for (int c = 0; c < ALPHABET; c++) { // Try all next characters
            if (state == m) {
                // Once the pattern is fully matched, stay in the 'matched' state
                next_state[state][c] = m;
                continue;
            }
            char next_char = 'A' + c;

            // Try to extend the current prefix
            int j = state;
            while (j > 0 && pattern[j] != next_char) {
                j = prefix[j - 1];
            }
            if (pattern[j] == next_char) {
                j++;
            }
            next_state[state][c] = j;
        }
    }

    // Step 3: DP array
    // dp[position][state]: number of ways to form string of length 'position' and partial match length 'state'
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1; // Start with empty string and no prefix matched

    for (int pos = 0; pos < n; pos++) { // For each position in the string
        for (int state = 0; state <= m; state++) { // For each current matching state
            for (int c = 0; c < ALPHABET; c++) { // Try all 26 characters
                int next = next_state[state][c];
                if (next == m) {
                    // If the pattern is fully matched, stay in absorbing matched state
                    dp[pos + 1][m] = (dp[pos + 1][m] + dp[pos][state]) % MOD;
                } else {
                    // Otherwise, move to the next matching state
                    dp[pos + 1][next] = (dp[pos + 1][next] + dp[pos][state]) % MOD;
                }
            }
        }
    }

    // Step 4: Final answer is all strings where the pattern has been matched (absorbing state)
    cout << dp[n][m] << endl;

    return 0;
}
