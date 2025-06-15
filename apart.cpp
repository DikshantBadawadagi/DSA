#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>stud(n);
    for(int i=0; i<n; i++){
        cin>>stud[i];
    }
    vector<int>apart(m);
    for(int i=0; i<m; i++){
        cin>>apart[i];
    }
    sort(stud.begin(), stud.end());
    sort(apart.begin(), apart.end());
    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(abs(stud[i] - apart[j]) <= k){
            ans++;
            i++;
            j++;
        } else if(stud[i] < apart[j]){
            i++;
        } else {
            j++;
        }
    }
    cout<<ans<<endl;
}