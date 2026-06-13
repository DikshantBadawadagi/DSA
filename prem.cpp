#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {

    //fast Io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(n == 4){
        cout<<"2 4 1 3"<<endl;
        return 0;
    }

    if(n <= 3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    if(n%2 == 0){
        for(int i=0;i<n/2;i++){
            cout<<i + 1<<" "<<i + n/2 + 1<<" ";
        }
    }
    else {
        for(int i=0;i<n/2;i++){
            cout<<i + 1<<" "<<i + n/2 + 2<<" ";
        }
        cout<<n/2 + 1<<" ";

    }
}