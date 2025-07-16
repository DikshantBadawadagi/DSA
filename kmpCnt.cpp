#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "ana";
    string t = "bananas";
    string comb = s + "#" + t;
    int n = comb.length();
    vector<int>pref(n,0);
    int j =0;
    for(int i=1;i<n;i++){
        while(j > 0 && comb[i] != comb[j]){
            j = pref[j-1];
        }
        if(comb[i] == comb[j]){
            j++;
            pref[i] = j;
        } else {
            pref[i] = 0;
        }
    }
    for(int i=0;i<n;i++){
        // cout<<pref[i]<<" ";
        if(pref[i] == s.length()){
            cout<<i - 2 * s.length() << " ";
        }
    }
}