#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool flag = 0;
void PrintSubsetSum(int i, int n,int set[], int target,vector<int>&subset ){

    if(target == 0){
        flag = 1;
        for(int i=0;i<subset.size();i++){
            cout<<subset[i]<<" ";
        }
        return;
    }
    if(i==n){
        return;
    }

    PrintSubsetSum(i+1,n,set,target,subset);

    if(set[i] <= target){
        subset.push_back(set[i]);
        PrintSubsetSum(i+1,n,set,target-set[i],subset);
        subset.pop_back();
    }


}


int main()
{
    // Test case 1
    int set[] = { 1, 2, 1 };
    int sum = 3;
    int n = sizeof(set) / sizeof(set[0]);
    vector<int> subset;
    PrintSubsetSum(0, n, set, sum, subset);
}