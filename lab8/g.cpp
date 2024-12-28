#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    int q;
    cin >> q;

    vector<int> results(q);

    for (int i = 0; i < q; ++i) {
        int L, R;
        cin >> L >> R;

        string substring = S.substr(L - 1, R - L + 1);

        int count = 0;
        size_t pos = S.find(substring);
        while (pos != string::npos) {
            ++count;
            pos = S.find(substring, pos + 1);
        }

        results[i] = count;
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}