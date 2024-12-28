#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int upperBound(const vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; 
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }

    for (int i = 0; i < q; i++) {
        int key;
        cin >> key;
        cout << upperBound(arr, n, key) + 1 << endl;
    }

    return 0;
}