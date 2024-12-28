#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int cookies;
            cin >> cookies;
            if (minHeap.size() < k) {
                minHeap.push(cookies);
                totalSum += cookies;
            } else if (minHeap.size() == k && cookies > minHeap.top()) {
                totalSum += cookies - minHeap.top();
                minHeap.pop();
                minHeap.push(cookies);
            }
        } else if (command == "print") {
            cout << totalSum << endl;
        }
    }

    return 0;
}
