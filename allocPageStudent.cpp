#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>pg,int mid){
    int count=1;
    long long pagesStudent =0;
    for(int i=0;i<pg.size();i++){
        if(pagesStudent + pg[i] <= mid){
            pagesStudent += pg[i];
        }
        else{
            count++;
            pagesStudent = pg[i];
        }
    }
    return count;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>pg(n);
    int max = INT_MIN,sum=0;
    for(int i=0;i<n;i++){
        cin>>pg[i];
    }
    if(m>n)  {
        cout<<-1;
        return -1;
        }

    int low= *max_element(pg.begin(),pg.end());
    int high= accumulate(pg.begin(),pg.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
       int students = countStudents(pg,mid);
       if(students > m){
        low = mid+1;
       }
       else{
        high = mid-1;
       }
    }
    cout<<low;

}