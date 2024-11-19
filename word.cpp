#include <iostream>
#include <cctype>  // For tolower and toupper
#include <string>  // For string operations
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt1 = 0, cnt2 = 0;

    for (char c : s) {
        if (islower(c))  
            cnt1++;
        else if (isupper(c))  
            cnt2++;
    }

    if (cnt1 >= cnt2) {
        for (char &c : s) {
            c = tolower(c);
        }
    } else {
        for (char &c : s) {
            c = toupper(c);
        }
    }

    cout << s;
    return 0;
}
