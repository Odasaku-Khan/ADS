#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o'
        || c == 'u')
            cout << c;
    }
    for (char c : s) {
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o'
        || c == 'u'))
            cout << c;
    }
    return 0;
}