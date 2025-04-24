#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (long long i = 0; i < n; i++){ 
            cin >> a[i];
        }
        for (long long i = 0; i < m; i++){
             cin >> b[i];
        }
        vector<long long> pref(m +1,n), sufi(m +1,-1);
        pref[0] =-1;
        long long j = 0;
        for (long long i =0; i <n && j<m;++i) {
            if (a[i] >=b[j]) {
                pref[j +1] = i;
                ++j;
            }
        }
        j = m -1;
        sufi[m] =n;
        for (long long i =n -1; i >=0 && j >=0;--i) {
            if (a[i] >=b[j]) {
                sufi[j] =i;
                --j;
            }
        }

        if (pref[m]<n) {
            cout<<0<<endl;
            continue;
        }
        long long ans = INT_MAX;
        for (long long i = 1;i<=m;++i) {
            if (pref[i - 1]<sufi[i]) {
                ans = min(ans, b[i - 1]);
            }
        }
        if(ans == INT_MAX) {
            cout <<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }

    return 0;
}

