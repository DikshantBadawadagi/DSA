 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

void getPermu(vector<int>&ds,vector<int>&num,vector<vector<int>>&ans,map<int,int>&mpp){

    if(ds.size()==num.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<num.size();i++){
    if(mpp[num[i]]!=1){
        ds.push_back(num[i]);
        mpp[num[i]] = 1;
        getPermu(ds,num,ans,mpp);
        mpp[num[i]] = 0;
        ds.pop_back();
        }
    }
    
}
 vector<vector<int>> main() {
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    map<int,int>mpp;
    vector<int>ds;
    vector<vector<int>>ans;
     getPermu(ds,num,ans,mpp);
    return ans;
 }