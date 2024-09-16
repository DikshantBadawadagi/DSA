#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>inp(n);
    for(int i=0;i<n;i++) {
        cin>>inp[i];
        if(inp[i] == 1){
            cout<<"HARD";
            return 0;
        }
        }
        cout<<"EASY";
}