#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t,n;
    cin >> t;

    while(t--){
    int count=0;
        cin>>n;
        char a[n];
        for(int i=0;i<n;i++){
           cin>>a[i];
        }
        for(int j=0;j<n;j++){
            if(a[j] == '1'){
               count++;
            }
        }
        // cout<<count;
        if(count&1){
            cout << "NO" << endl;
            continue;
        }
        if(count==2){
            int flag=0;
            for(int i=0;i<n-1;i++){
                if(a[i]=='1' && a[i+1]=='1'){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;

    }
}