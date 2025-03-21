#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int,int>>num(n);
        for(int i=0;i<n;i++) {
            cin>>num[i].second>>num[i].first;
        }

        sort(num.begin(),num.end());
        int lmini = INT_MAX,ind=-1;
        for(int i=n-2;i>=0;i--) {
            lmini = min(lmini,num[i+1].second);
            if(num[i].first < lmini){
                ind = i;
                break;
            }
        }
        if(ind == -1)cout<<-1<<endl;
        else{
            for(int i=0;i<n;i++) {
                if(i <= ind)cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
        }
    }

}