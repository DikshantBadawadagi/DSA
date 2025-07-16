// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//     int n = 4;
//     vector<int>warehouse = {2,4,1,3};
//     int q =1;
//     vector<pair<int,int>>catalog = {{5,7}};
    
//     int sum=0;
//     sort(warehouse.begin(),warehouse.end());
//     vector<int>prefixSum(n,0);
//     prefixSum[0] = warehouse[0];
//     for(int i=1;i<n;i++){
//         prefixSum[i] = prefixSum[i-1] + warehouse[i];
//     }
    
//     for(auto cat : catalog){
//         int ans = INT_MAX;
//         int miniCap = cat.first;
//         int miniCombCap = cat.second;

//         int ind = upper_bound(warehouse.begin(),warehouse.end(),miniCap) - warehouse.begin();
//         int maxiSum = prefixSum[ind-1];

//         for(int i=0;i<n;i++){
//             int token =0;
//             if(warehouse[i] < miniCap){
//                 token+=miniCap - warehouse[i];
//             }
//             if(i < ind){
//                 if(maxiSum - warehouse[i] < miniCombCap){
//                     token += miniCombCap - (maxiSum - warehouse[i]);
//                 }
//             }
//             ans = min(ans,token);
//         }
//         cout<<ans<<endl;
//     }
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> warehouse = {2, 4, 1, 3};
    int q = 1;
    vector<pair<int, int>> catalog = {{5, 7}};
    
    for(auto cat : catalog) {
        int miniCap = cat.first; // Minimum capacity
        int miniCombCap = cat.second; // Minimum combined backup capacity
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int tokens = 0;
            int selectedCap = warehouse[i];
            // Tokens to meet minimum capacity for warehouse i
            if(selectedCap < miniCap) {
                tokens += miniCap - selectedCap;
                selectedCap = miniCap;
            } else if(selectedCap > miniCap) {
                // Leftover capacity cannot be used for backup
                selectedCap = miniCap;
            }
            
            // Calculate backup capacity from other warehouses
            int backupCap = 0;
            for(int j = 0; j < n; j++) {
                if(j != i) {
                    backupCap += warehouse[j];
                }
            }
            backupCap -= (warehouse[i] - selectedCap); // Exclude leftover
            
            // Add tokens to meet backup requirement
            if(backupCap < miniCombCap) {
                tokens += miniCombCap - backupCap;
            }
            
            ans = min(ans, tokens);
        }
        cout << ans << endl;
    }
    return 0;
}