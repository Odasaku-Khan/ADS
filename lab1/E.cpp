#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<int> s(n);
    vector<int> z(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    queue<int> boris;
    queue<int> nurik;

    for (int card : s) {
        boris.push(card);
    }
    for (int card : z) {
        nurik.push(card);
    }
    int c = 0;
    int max=1000000;
    while (!nurik.empty() && !boris.empty()) {
        c++;
        if (c >=max) {
            cout << "blin nichya" << endl;
            return 0;
        }

        int q1 = nurik.front();
        int w1 = boris.front();
        nurik.pop();
        boris.pop();
        if (q1 == 0 && w1 == 9) {
            nurik.push(w1);
            nurik.push(q1);
        } else if (w1 == 0 && q1 == 9) {
            boris.push(w1);
            boris.push(q1);
        } else if (q1 > w1) {
            nurik.push(q1);
            nurik.push(w1);
        } else {
            boris.push(q1);
            boris.push(w1);
        }
    }

    if (boris.empty()) {
        cout << "Nursik " << c << endl;
    } else {
        cout << "Boris " << c << endl;
    }

    return 0;
}