#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string pat ;
    cin >> s >> pat;
    int n = s.size();
    int m = pat.size();
    string combined = pat + "$" + s;
    int nm = combined.size();
    vector<int> z(nm, 0);
    int l=0,r=0;
    for(int i=1;i<nm;i++){
        if( i > r){
            l=r=i;
            while(r < nm && combined[r] == combined[r-l]){
                r++;
            }
            z[i] = r-l;
            r--;
        }
        else{
            int k = i-l;
            if(z[k] < r-i+1){
                z[i] = z[k];
            }else{
                l = i;
                while(r < nm && combined[r] == combined[r-l]){
                    r++;
                }
                z[i] = r-l;
                r--;
            }
        }
    }
    int count = 0;
    for(int i = m + 1; i < nm; i++) {
        if(z[i] == m) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}