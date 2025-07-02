#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class job {
    public:
    int id;
    int deadline;
    int profit;
        job(int id, int deadline, int profit) {
            this->id = id;
            this->deadline = deadline;
            this->profit = profit;
        }
};

static bool comp(const job & a,const job &b){
    return a.profit > b.profit;
};
int main() {
    int n;
    cin>>n;
    int maxi = 0;

    vector<job> jobs;
    for(int i = 0; i < n; i++) {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        maxi = max(maxi, deadline);
        jobs.push_back(job(id, deadline, profit));
    }

    sort(jobs.begin(),jobs.end(),comp);
    vector<int>sch(n+1,-1);
    int totalProfit = 0;
    for(int i = 0; i < n; i++) {

}