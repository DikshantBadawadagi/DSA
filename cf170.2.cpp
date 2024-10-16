#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    vector<long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int, int> freqMap;
    for (int num : a) {
        freqMap[num]++;
    }

     set<pair<int, int>> freqSet; 
    for (const auto& entry : freqMap) {
        freqSet.insert({entry.first, entry.second});
    }

   
    int maxi = 0;     
    int another = 0;  
int count =0;
 auto it = freqSet.begin();
        if (it != freqSet.end()) {
            maxi = it->second; // Initialize maxi with the first element's frequency
            another = 0; 

            for (auto current = it; current != freqSet.end(); ++current) {
                count++; // Increment count of distinct numbers

                // Check for consecutive numbers
                if (current != freqSet.begin()) {
                    int previousNum = prev(current)->first;
                    int currentNum = current->first;

                    if (currentNum == previousNum + 1) {
                        maxi += current->second; // Add frequency if consecutive
                    } else {
                        another = max(another, maxi); // Update overall max if the sequence breaks
                        maxi = current->second; // Reset maxi for the new sequence
                        count = 1; // Reset count to 1 for the new distinct number
                    }
                }

                // If count exceeds k, adjust the window
                while (count > k) {
                    // Move to the next number in the frequency set to maintain k distinct numbers
                    auto firstInWindow = it;
                    firstInWindow++; // Move to the next distinct number
                    if (firstInWindow != freqSet.end()) {
                        count--; // Decrease count as we are excluding the first number
                        maxi -= prev(firstInWindow)->second; // Remove the frequency of the excluded number
                    }
                }

                // If count equals k, update another with current maxi
                if (count == k) {
                    another = max(another, maxi); // Update another with current window sum
                }
            }

            // Final check after the loop
            another = max(another, maxi); // Final check to ensure last segment is considered
        }

        cout << another << endl; // Output the result for the current test case
    }

}


