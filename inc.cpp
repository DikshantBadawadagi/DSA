#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long prev = -1, ans = 0;
    
    for (int i = 0; i < n; i++) {
        long long curr;
        cin >> curr;
        
        if (prev != -1) {
            if (curr < prev) {
                ans += (prev - curr);

            } else {

                prev = curr;
            }
        } else {
            prev = curr;
        }
    }
    
    cout << ans << "\n";
    return 0;
}