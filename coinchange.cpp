#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>coins = {1,10,20,50,100,200,500};
    vector<int>ans;
    int v,count=0;
    cin>>v;
    for(int i=coins.size()-1;i>=0;i--){
        while(v>=coins[i]){
            v-=coins[i];
            count++;
            ans.push_back(coins[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   
    return 0;
}