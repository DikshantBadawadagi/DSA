#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Exam {
    int a, b;
};

bool compareExams(const Exam &e1, const Exam &e2) {
    if (e1.a != e2.a) return e1.a < e2.a;
    return e1.b < e2.b;
}

int main() {
    int n;
    cin >> n;

    vector<Exam> exams(n);
    for (int i = 0; i < n; i++) {
        cin >> exams[i].a >> exams[i].b;
    }

    sort(exams.begin(), exams.end(), compareExams);

    int best_day = 0;
    for (int i = 0; i < n; i++) {
        if (exams[i].b >= best_day) {
            best_day = exams[i].b;
        } else {
            best_day = exams[i].a;
        }
    }

    cout << best_day << endl;

    return 0;
}