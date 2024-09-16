#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n; 
       stack<int> parts;
    int placeValue = 1;
    int temp = n;

    // Find the highest place value
    while (temp >= 10) {
        temp /= 10;
        placeValue *= 10;
    }

    // Store each digit with its place value in the stack
    while (placeValue > 0) {
        int digit = n / placeValue;
        n %= placeValue;

        if (digit != 0) {
            parts.push(digit * placeValue);
        }

        placeValue /= 10;
    }
    cout << parts.size() << endl;

    // Print the parts in reverse order
    while (!parts.empty()) {
        cout << parts.top() << " ";
        parts.pop();
    }
    cout << endl;
}
}


