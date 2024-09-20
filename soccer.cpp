#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long x1,y1,x2,y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        if(x1==x2 && y1==y2){
            cout<<"Yes"<<endl;
        }
        else if(x1>y1 && x2>y2 || y1>x1 && y2>x2){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
}