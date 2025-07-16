// vector<int> commonCharsAroundEachIndex(const string &s) {
//     int n = s.length();
//     vector<bitset<26>> prefix(n),suffix(n);
//     vector<int>res(n,0);

//     bitset<26> bits;
//     for (int i=0;i<n;++i) {
//         prefix[i] = bits;
//         bits.set(s[i] -'a');
//     }

//     bits.reset();
//     for (int i =n -1;i>= 0;--i) {
//         bits.set(s[i] -'a');
//         suffix[i] = bits;
//     }

//     for (int i=0; i<n;++i) {
//         bitset<26> common = prefix[i] & suffix[i];
//         res[i] = common.count();
//     }
//     return res;
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "abbac";
    bitset<26>bits;
    int n = s.length();
    vector<bitset<26>>prefix(n),suffix(n);

    for(int i=0;i<n;i++){
        prefix[i] = bits;
        bits.set(s[i] - 'a');
    }
    bits.reset();
    for(int i=0;i<n;i++){
        bits.set(s[i] - 'a');
        suffix[i] = bits;
    }

    for(int i=0;i<n;i++){
        bitset<26>common = prefix[i] & suffix[i];
        cout<<common.count()<<" ";
    }
}