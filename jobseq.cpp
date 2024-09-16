#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sortFunc(const pair<pair<int,int>,int>&a , const pair<pair<int,int>,int> &b){
    return a.first.second > b.first.second;
}
int main(){
    int n,dead;
    cin>>n>>dead;
    vector<pair<pair<int,int>,int>>jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i].first.first>>jobs[i].first.second>>jobs[i].second;
    }
    sort(jobs.begin(),jobs.end(),sortFunc);
    int seq[dead];
    for(int i=0;i<dead;i++){
        seq[i] =-1;
    }
    int totalprofit=0;
    for(int i=0;i<n;i++){
        int deadline = jobs[i].second;
        int profit = jobs[i].first.second;
        
        int slot = min(dead-1,deadline-1);
        while(slot>=0&&seq[slot]!=-1){
          slot--;
        }
        if(slot>=0){
            seq[slot] = i;
            totalprofit+=profit;
        }
    }
    for(int i=0;i<dead;i++){
        cout<<seq[i]<<" ";
    }

}