#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--){
        int n,r;
        cin>>n>>r;
        int sum=0;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum+=vec[i];
        }

        int sum1=0;
        int sum2=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vec[i]%2==0){
                sum1+=vec[i];
                cnt+=vec[i]/2;
            }
            else{
                sum1+=vec[i]-1;
                sum2+=1;
                cnt+=(vec[i]-1)/2;
            }
        }
        int left;
        if(sum2%2==0){
            cnt+=sum2/2;
            left=r-cnt;
            sum1+=2*left;
        }
        else{
            cnt+=(sum2-1)/2;
            cnt++;
            sum1++;
            left=r-cnt;
            sum1+=2*left;
        }
        cout<<min(sum,sum1)<<endl;

    }
}