#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    long long t;
    cin >> t;

    while (t--) {
        long long n, h;
        cin >>n>>h;

        long long maxi1 =0, maxi2 =0;
        for (int i=0; i<n;i++) {
            int s;
            long long d;
            cin >>s>>d;
            if (s ==1) {
                maxi1 = max(maxi1,d);
            } else {
                maxi2 = max(maxi2,d);
            }
        }

        long long l =1, r =2*h,res =-1;
        while (l <= r) {
            long long mid =(l + r) / 2;
            long long s2 = mid / 2;
            long long temp;

            if (maxi1 == 0) {
                temp = s2*maxi2;
            } else if (maxi2 == 0) {
                temp = mid*maxi1;
            } else {
                long long sub = maxi2 - 2*maxi1;
                if (sub > 0) {
                    temp = mid*maxi1 + s2*(maxi2 - 2*maxi1);
                } else {
                    temp = mid*maxi1;
                }
            }

            if (temp >= h) {
                res =mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout <<res<<endl;
    }
}
