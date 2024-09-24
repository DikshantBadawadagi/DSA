#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 
    int lcp(int num1, int num2) {
        int count = 0;
        string n1 = to_string(num1), m1 = to_string(num2);
        
        for (int i = 0; i < min(n1.size(), m1.size()); i++) {
            if (n1[i] == m1[i]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxLcp = 0;  

        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                int currentLcp = lcp(arr1[i], arr2[j]);
                maxLcp = max(maxLcp, currentLcp);
            }
        }
        return maxLcp;
    }
};
