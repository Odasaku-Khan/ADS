#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<char, int> frequency;
        queue<char> q;
        vector<string> result;
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ch;
            frequency[ch]++;
            if (frequency[ch] == 1) {
                q.push(ch);
            }
            while (!q.empty() && frequency[q.front()] > 1) {
                q.pop();
            }
            if (q.empty()) {
                result.push_back("-1");
            } else {
                result.push_back(string(1, q.front()));
            }
        }
        for (const string& res : result) {
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}