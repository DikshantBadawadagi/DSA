#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        int odd=0, even=0;
        for (int i =0; i <n;i++) {
            cin >> nums[i];
            if (nums[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        int sum = nums[0];
        for (int i =1; i <n;i++) {
            sum = __gcd(sum, nums[i]);
        }
        vector<int>divi(n);
        for (int i =0; i <n;i++) {
           divi[i] =nums[i]/sum;
        }
        
        bool flag = true;
        for (int i =1;i <n;i++) {
            if (divi[i] != divi[0]) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            cout<<"NO"<< endl;
        } else {
            cout <<"YES"<<endl;
            vector<int>ans(n, 2); 
            for (int i =0; i< n;i++) {
                if (divi[i] != 1) {
                    ans[i] = 1;
                    break;
                }
            }

            for (int i =0; i <n;i++) {
                cout<<ans[i]<< " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}