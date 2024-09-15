#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>num(n);
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        string s;
        
            cin>>s;
        
        if(s[0] == 'R'){
            cout<<0<<endl;
            continue;
        }
        int l=0,r=1,sum=num[0];
        while(r < n){
            if(s[r] == 'L'){
                sum +=num[r];
                r++;
            }
            else{
                sum +=num[r];
                l = r+1;
                r = l+1;
            }
        }
        cout<<sum<<endl;
    }
}