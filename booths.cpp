#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    string ss  = s+ s;
    int n = s.size();
    vector<int>f(2 * n, -1);
    f[1] = 0;
    int k = 1;
    for(int i=2;i<2*n;i++){
        if(s[i] == s[i-k]){
            f[i] = f[i-k]+1;
        }else{
            
        }
    }
}