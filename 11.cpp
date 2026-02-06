#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main( ){
    vector<string>num;
    num.push_back("0");
    num.push_back("1");

    for(int i=2;i<11;i++){
        num.push_back(num[i-1] + '1');
    }

    int t;
    cin>>t;

    while(t--){
        int x;
        cin>>x;
        
        while(x >= 0){
            if(x%11 == 0){
                cout<<"YES"<<endl;
                break;
            }
            x-=111;

        }
        if(x < 0){
            cout<<"NO"<<endl;
        }
        
        
    }
}