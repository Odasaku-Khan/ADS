#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool check(const vector<int>& arr, long f, int capacity) {
    int count = 0;
    for (int i : arr) {
        count += i / capacity;
        if (i % capacity > 0) count++;
    }
    return count <= f;
}

int BinarySearchCapacity(const vector<int>& arr, int n, long f) {
    int low = 1, high = arr[n - 1];
    int res = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, f, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    int n;
    long f;
    cin >> n >> f;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << BinarySearchCapacity(arr, n, f) << endl;
    return 0;
}
