#include <iostream>
#include <vector>
using namespace std;

int main () {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> mat(1001, vector<long long>(1001));
    vector<long long> row(1001), col(1001);

    for (long long i = 0; i < n; i++) {
        row[i] = i; 
        for (long long j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for(long long j=0;j<m;j++)col[j]=j;

    for (long long i = 0; i < k; i++) {
        int ch,first,second;
        cin >> ch >> first >> second;

        long long x = first - 1;  
        long long y = second - 1; 

        if (ch == 'r') 
            swap(row[x], row[y]);
        else if (ch == 'c') 
            swap(col[x], col[y]);
        else 
            cout << mat[row[x]][col[y]] << endl;
    }
}
