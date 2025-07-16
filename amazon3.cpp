#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    string x,y,z;
    x = "AERB",y ="ATRC",z="AGCB";
    int n = x.size();
    if(x.length() != y.length())return -1;
    if(x.length() != z.length()){
        for(int i=0;i<n;i++){
            cout<<'[';
            for(char c='A';c<='Z';c++){
                cout<<c;
            }
            cout<<']';
        }
        return 0;
    }
    int ind = -1;
    for(int i=0;i<n;i++){
        if(z[i] == x[i] || z[i] == y[i])continue;
        else {ind = i;break;}
    }
    if(ind == -1){cout<<-1<<endl;return 0;}
    for(int i=0;i<n;i++){
            cout<<'[';
            for(char c='A';c<='Z';c++){
                if(i == ind && c == z[i])continue;
                cout<<c;
            }
            cout<<']';
    }
}