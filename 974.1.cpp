#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>gold(n);
        for(int i=0;i<n;i++){
            cin>>gold[i];
        }
        int g=0,count=0;
        for(int i=0;i<n;i++){
            if(gold[i] == 0 && g == 0){
                continue;
            }
            if(gold[i] == 0 && g != 0){
                count++;
                g--;
            }
            else if(gold[i] !=0){
                g+=gold[i];
            }
        }
        cout<<count<<endl;
    }
}