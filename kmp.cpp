// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     string s = "abcaby";
//     string t = "abxabcabcaby";
//     vector<int>pref(s.length(),0);

//     int j = 0;
//     int n = s.length();

//     for(int i=1;i<n;i++){
//         if(s[i] == s[j]){
//             pref[i] = j+1;
//             j++;
//         }else{
//             j = pref[j-1];
//             while(j > 0 && s[i]!=s[j])j = pref[j-1];
//             if(s[i] == s[j]){
//                 pref[i] = j+1;
//                 j++;
//             }else{
//                 pref[i] = 0;
//             }
//         }
//     }
//     // for(int i=0;i<n;i++){
//     //     cout<<pref[i]<<" ";
//     // }
//     int m   = t.length();
//     j=0;
//     vector<int>occurences;
//     #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     string s = "abcaby";
//     string t = "abxabcabcaby";
//     vector<int>pref(s.length(),0);

//     int j = 0;
//     int n = s.length();

//     for(int i=1;i<n;i++){
//         if(s[i] == s[j]){
//             pref[i] = j+1;
//             j++;
//         }else{
//             j = pref[j-1];
//             while(j > 0 && s[i]!=s[j])j = pref[j-1];
//             if(s[i] == s[j]){
//                 pref[i] = j+1;
//                 j++;
//             }else{
//                 pref[i] = 0;
//             }
//         }
//     }
//     // for(int i=0;i<n;i++){
//     //     cout<<pref[i]<<" ";
//     // }
//     int m   = t.length();
//     j=0;
//     vector<int>occurences;
//     for(int i=0;i<m;i++){
//         if(t[i] == s[j]){
//             j++;
//             i++;
//         }
//         else{
//             while(j > 0 && t[i] != s[j]){
//                 j = pref[j-1];
//             }
//             if(t[i] == s[j]){
//                 j++;
//                 i++;
//             }
//             else{
//                 j = 0;
//             }
//         }
//         if(j == n){
//             occurences.push_back(i-n+1);
//             j = pref[j-1];
//         }
//     }
// }
// }

#include <iostream>
#include <vector>
using namespace std;

// Build prefix (pi) array
vector<int> buildPrefixFunction(const string &pattern) {
    int n = pattern.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// KMP pattern matching
vector<int> KMP(const string &text, const string &pattern) {
    vector<int> pi = buildPrefixFunction(pattern);
    vector<int> occurrences;

    int n = text.size(), m = pattern.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            occurrences.push_back(i - m + 1); // 0-based index of match
            j = pi[j - 1]; // look for next match
        }
    }

    return occurrences;
}

int main() {
    string pattern = "abcaby";
    string text = "abxabcabcaby";

    vector<int> matches = KMP(text, pattern);

    for (int idx : matches) {
        cout << "Pattern found at index: " << idx << endl;
    }

    return 0;
}
