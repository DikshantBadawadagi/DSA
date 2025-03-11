#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
    long long t;
    cin>>t;
    while(t--){

        long long n;
        cin>>n;
        vector<int>nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        vector<int>curr(2,0),next(2,0),next2(2,0);
        next[1] = nums[n-1];
        next[0] = 0;
        for(int ind=n-2;ind>=0;ind--){
            for(int flag =0;flag<2;flag++){

            int one=0,two=0;
            if(flag) {  
                one = nums[ind] + next[0];
                two = (int)1e9;  
                if(ind + 1 < n) {
                    two = nums[ind] + nums[ind+1] + next2[0];
                }
            } else {   
                one = next[1];
                two = (int)1e9; 
                if(ind + 1 < n) {
                    two = next2[1];
                }
            }
            curr[flag] = min(one, two);
            }
            next2 = next;
            next = curr;
        }
    
    cout<<next[1]<<endl;
    }
}