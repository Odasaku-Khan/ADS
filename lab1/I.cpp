#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string votes;
    cin >> votes;

    queue<int> sakayanagi, katsuragi;

    for (int i = 0; i < n; ++i) {
        if (votes[i] == 'S') {
            sakayanagi.push(i);
        } else {
            katsuragi.push(i);
        }
    }

    while (!sakayanagi.empty() && !katsuragi.empty()) {
        int s_student = sakayanagi.front();
        int k_student = katsuragi.front();
        sakayanagi.pop();
        katsuragi.pop();

        if (s_student < k_student) {
            sakayanagi.push(s_student + n);
        } else {
            katsuragi.push(k_student + n);
        }
    }

    if (!sakayanagi.empty()) {
        cout << "SAKAYANAGI" << endl;
    } else {
        cout << "KATSURAGI" << endl;
    }

    return 0;
}