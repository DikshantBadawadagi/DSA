#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<int>nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        bool turn=true;

        long long i = 0,ans=0;
        while(i < n){
            if(turn){
                if(nums[i] == 1){
                    ans++;
                    if(i != n-1 && nums[i+1] == 0){
                        i+=2;
                    }
                    else{
                        if(i!= n-1 && nums[i+1] == 0){
                            i+=2;
                        }
                        else{
                        i++;
                    }
                    }
                }
                else{
                    i++;
                }
                turn = !turn;
            }
            else{
                if(nums[i] == 1){
                    if(i != n-1 && nums[i+1] == 1){
                        i+=2;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    if(i != n-1 && nums[i+1] == 1){
                        i+=2;
                    }
                    else{
                        i++;
                    }
                }
                turn = !turn;
            }
        }
        cout<<ans<<endl;
    }
}