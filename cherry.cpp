#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >>t;
    while (t--) {
        long long n, k;
        cin >>n>>k;
        vector<long long> a(n),b(n);
        for (int i =0; i <n;i++) {
            cin >> a[i];
        }
        for (int i =0; i <n;i++) {
            cin >> b[i];
        }

        bool flag = false;
        long long x = -1; 
        bool e = false;
        for (int i =0; i<n;i++) {
            if (b[i] !=-1) {
                long long sum = a[i] + b[i];
                if (x ==-1) {
                    x =sum;
                    flag =true;
                } else if (x !=sum) {
                    cout<< 0<<endl;
                    e = true;
                    break;
                }
            }
        }
        if(e){
            continue;
        }

        if (flag) {
            bool possi = true;
            for (int i = 0; i <n;i++) {
                if (b[i] == -1) {
                    long long bi = x -a[i];
                    if (bi < 0 ||bi > k) {
                        possi = false;
                        break;
                    }
                }
            }
            cout <<(possi?1 :0)<<endl;
        } else {
            long long mini = *min_element(a.begin(), a.end());
            long long maxi = *max_element(a.begin(), a.end());
            long long minx = maxi;
            long long maxx = mini + k;
            long long res = max(0LL, maxx - minx + 1);
            cout <<res<<endl;
        }
    }
    return 0;
}