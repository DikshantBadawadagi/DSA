#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    unordered_map<char,int> mp1;

    for(auto c : s1){
        if(isspace(c))continue;
        mp1[c]++;
    }
    for(auto c : s2){
        if(isspace(c))continue;
        if(mp1[c] == 0){
            cout<<"NO"<<endl;
            return 0;
        }
        mp1[c]--;
    }
    cout<<"YES"<<endl;
}