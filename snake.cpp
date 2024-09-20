#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
        bool b=true;
    for(int i=0;i<m-1;i++){
        if(i%2==0){
        for(int j=0;j<n;j++){
            cout<<"#";
        }
        cout<<endl;
         }
        else{
        if(b==true){
            for(int j=0;j<n-1;j++){
                cout<<".";
            }cout<<"#"<<endl;
            b=false;
        }
        else{
            cout<<"#";
            for(int j=0;j<n-1;j++){
                cout<<".";
            }
            cout<<endl;
            b=true;
        }
         }

    }
    while(n>0){
        cout<<"#";
        n--;
    }
}