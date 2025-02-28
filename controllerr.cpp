#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long q;
    cin>>q;
    vector<pair<int,int>>queries(q);
    long long p=0,m=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '+')p++;
        else m++;
    }
    for(int i=0;i<q;i++){
        cin>>queries[i].first>>queries[i].second;
    }
    for(int j=0;j<q;j++){
        int x = queries[j].first;
        int y = queries[j].second;
    
    if(p == m){
        cout<<"YES"<<endl;
        continue;
    }
    if(y == x){
        cout << "NO" << endl;
        continue;
    }
    else{
        long long t = p-m;
        long long ans = t*y;
        if(ans % (y-x) != 0){
            cout<<"NO"<<endl;
            continue;
        }
        ans/=(y-x);
        if(ans >= -m && ans <= p){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    }
}