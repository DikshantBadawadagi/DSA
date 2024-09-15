#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
        int n;
        cin>>n;
        vector<vector<int>>nums(n, vector<int>(2));
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a;
            nums[i][0] = a;
            cin>>b;
            nums[i][1] = b;
            if(nums[i][1]>=-1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

        
    }
