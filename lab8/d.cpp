#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<string> patterns(N);
        for (int i = 0; i < N; ++i) {
            cin >> patterns[i];
        }

        string text;
        cin >> text;

        unordered_map<string, int> frequency;
        int max_frequency = 0;

        for (const auto& pattern : patterns) {
            int count = 0;
            size_t pos = text.find(pattern);
            while (pos != string::npos) {
                ++count;
                pos = text.find(pattern, pos + 1);
            }
            frequency[pattern] = count;
            if (count > max_frequency) {
                max_frequency = count;
            }
        }

        cout << max_frequency << '\n';
        for (const auto& pattern : patterns) {
            if (frequency[pattern] == max_frequency) {
                cout << pattern << '\n';
            }
        }
    }

    return 0;
}