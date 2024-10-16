#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--){
        int n,r;
        cin>>n>>r;
        vector<int>fam(n);
        for(int i=0;i<n;i++){
            cin>>fam[i];
        }
        int happy=0,one=0;
        for(int i=0;i<n;i++){
            if(fam[i] % 2 ==0){
                happy+=fam[i];
                r--;
            }
            else{
                if(fam[i] == 1){one++;continue;}
                happy+=(fam[i]/2)*2;
                one++;
                r--;
            }
        }
        if(r>=one){
            cout<<happy+one<<endl;
        }
        else{
            cout<<happy + 2*r - one<<endl;
        }
        
    }
}