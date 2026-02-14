#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long x;
    cin >> x;

    long long best_a = 1, best_b = x;

    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            long long a = i;
            long long b = x / i;
            
            if (gcd(a, b) == 1) {

                best_a = a;
                best_b = b;
            }
        }
    }

    cout << best_a << " " << best_b << endl;

    return 0;
}