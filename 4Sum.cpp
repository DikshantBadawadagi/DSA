#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> main() {
    vector<int> arr = {-2,2,-1,0,0,1,2};
    int target = 0;
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i!=0 && arr[i+1] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=1 && arr[i+1] == arr[i-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum == target){
                vector<int>temp ={arr[i],arr[j],arr[k],arr[l]};
                   ans.push_back(temp);
                    if(k!=2 && arr[k+1] == arr[k]) k++;
                    if(l!=n-1 && arr[l] == arr[l+1])l--;

                }
                else if(sum > target) l--;
                else k++;
            }

        }
    }
    return ans;
}