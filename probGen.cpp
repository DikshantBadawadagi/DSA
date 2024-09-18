#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int m,n,ans=0;
        cin>>n>>m;
        string diff;
        int a[7]= {0};
        cin>>diff;
        for(char ch : diff){
            a[ch - 'A']+=1;
        }
        for(int i=0;i<7;i++){
            if(m-a[i]>0){
                ans+=(m-a[i]);
            }
        }
        cout<<ans<<endl;


    }
    
}