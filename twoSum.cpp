#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v= {3,2,4};
    int n = v.size();
    int target = 6;
    int left=0,right=n-1;
    sort(v.begin(),v.end());
    while(left<right){
        if((v[left] + v[right]) == target){
            cout<< v[left]<<v[right] << endl;
            return 0;
        }
        else if((v[left] + v[right]) < target){
            left ++;
        }
        else if((v[left] + v[right]) > target){
            right --;
        }
    }
        cout<<-1<<-1;


}