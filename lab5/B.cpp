#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        maxHeap.push(weight);
    }
    while (maxHeap.size() > 1) {
        int first = maxHeap.top(); maxHeap.pop();
        int second = maxHeap.top(); maxHeap.pop();
        
        if (first != second) {
            maxHeap.push(first - second);
        }
    }
    cout << (maxHeap.empty() ? 0 : maxHeap.top()) << endl;
    return 0;
}