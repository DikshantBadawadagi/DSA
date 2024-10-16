#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != t[i])break;
            else{
                cnt++;
            }
        }
        if(cnt !=0) cnt = cnt-1;
        cout<<s.size() + t.size() - cnt<<endl;
    }
}
