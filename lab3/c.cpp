#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upper_bound(const vector<int>& arr, int val) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int lower_bound(const vector<int>& arr, int val) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int get_answer(const vector<int>& arr, int l, int r) {
    return upper_bound(arr, r) - lower_bound(arr, l) + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        if (r1 >= l2) {
            if (l1 <= l2) {
                cout << get_answer(arr, l1, max(r1, r2)) << endl;
            } else {
                cout << get_answer(arr, l2, max(r1, r2)) << endl;
            }
        } else {
            cout << get_answer(arr, l1, r1) + get_answer(arr, l2, r2) << endl;
        }
    }

    return 0;
}