#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string g1,g2;
    cin>>g1;
    cin>>g2;
    long long cnt=0;
    map<char,int>mpp;
    if(g1.size() != g2.size()){cout<<"NO"<<endl;return 0;}
    for(int i=0;i<g1.size() && i < g2.size();i++){
        mpp[g1[i]]++;
        mpp[g2[i]]--;
         if (mpp[g1[i]] == 0) mpp.erase(g1[i]);
        if (mpp[g2[i]] == 0) mpp.erase(g2[i]);
        if(g1[i] != g2[i]){cnt++;}
    }
    
    if(mpp.empty() && cnt == 2 || cnt == 0){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
}