#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++) {
        int seats;
        cin >> seats;
        maxHeap.push(seats);
    }

    long long totalRevenue = 0;

    for (int i = 1; i <= m; i++) {
        int maxSeats = maxHeap.top();
        maxHeap.pop();
        totalRevenue += maxSeats; 
        if (maxSeats > 1) {
            maxHeap.push(maxSeats - 1); 
        }
    }
    cout << totalRevenue << endl;
    return 0;
}