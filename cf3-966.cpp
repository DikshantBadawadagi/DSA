#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        vector<int>numArray(n);
        for(int i=0;i<n;i++){
            cin>>numArray[i];
        }
        cin>>m;
        vector<string>str(m);
        for(int i=0;i<m;i++){
            cin>>str[i];
        }
        for(int i = 0; i < m; i++){
            if (numArray.size() != str[i].length()) {
                cout << "No" << endl;
                continue;
            }

            unordered_map<int, char> numToChar;
            unordered_set<char> usedChars;
            bool isValid = true;

            for (size_t j = 0; j < numArray.size(); ++j) {
                if (numToChar.find(numArray[j]) != numToChar.end()) {
                    if (numToChar[numArray[j]] != str[i][j]) {
                        isValid = false;
                        break;
                    }
                } else {
                    if (usedChars.find(str[i][j]) != usedChars.end()) {
                        isValid = false;
                        break;
                    }
                   
                    numToChar[numArray[j]] = str[i][j];
                    usedChars.insert(str[i][j]);
                }
            }

            if (isValid) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}