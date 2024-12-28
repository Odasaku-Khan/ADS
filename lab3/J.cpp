#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int>& arr, int H, int K) {
    int count = 0;
    for (int i : arr) {
        count += i / K;
        if (i % K > 0) count++;
    }
    return count <= H;
}

int BinarySearchSpeed(const vector<int>& arr, int n, int h, int max) {
    int low = 0, high = max;
    int res = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, h, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    int max = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    cout << BinarySearchSpeed(arr, n, h, max) << endl;
    return 0;
}
