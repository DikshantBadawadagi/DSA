#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        unordered_set<string>sub;
        for(int i=0;i<s.length();i++){
            string tmp = "";
            for(int j=i;j<s.length();j++){
                tmp+=s[j];
                sub.insert(tmp);
            }
        }
        if(sub.size() % 2 ==0){
            for(int i=0;i<s.length();i++){
                for(int j=i;j<s.length();j++){
                    cout<<s[j];
                }
                cout<<endl;
                break;
            }
        }
        else{
            cout<<-1<<endl;
        }

    }
}