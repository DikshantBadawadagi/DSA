#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        unordered_set<char> chars_in_s1(s1.begin(), s1.end());
    unordered_set<char> chars_in_s2(s2.begin(), s2.end());

    int missingCount = 0;

    // Count characters in s2 that are not in s1
    for (char ch : chars_in_s2) {
        if (chars_in_s1.find(ch) == chars_in_s1.end()) {
            missingCount++;
        }
    }
     
     cout<<s1.size() + missingCount<<endl;
    }
}